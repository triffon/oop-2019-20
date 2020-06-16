#include <iostream>
#include "Player.hpp"
#include "Game.hpp"
#include "Solid.hpp"
#include "Util.hpp"
#include "Collectable.hpp"

const sf::Keyboard::Key KEY_LEFT     = sf::Keyboard::Key::A;
const sf::Keyboard::Key KEY_RIGHT    = sf::Keyboard::Key::D;
const sf::Keyboard::Key KEY_JUMP     = sf::Keyboard::Key::Space;
const float DEFAULT_ACC              = 1;
const float DEFAULT_MAX_HSPD         = 5;
const float DEFAULT_JUMP_FORCE       = 12.0f;
const float DEFAULT_GRAVITY          = 0.6f;
const float DEFAULT_HDRAG            = 0.8f;
const unsigned char ID               = 'a';
const sf::Color DEFAULT_COLOR        = sf::Color::Green;
const sf::Vector2f GUI_SCORE_POS     = { 10, 6 };
const sf::Vector2f GUI_SHADOW_OFFSET = { 2, 2 };
const size_t SCORE_TEXT_SIZE         = 24;


Player::Player(const sf::Vector2f& pos, const sf::Vector2f& size)
    : GameObj(pos, size)
    , Entity(pos, size)
    , PhysicsObj(pos, size, DEFAULT_GRAVITY)
    , Solid(pos, size)
    , m_acc(DEFAULT_ACC)
    , m_maxhspd(DEFAULT_MAX_HSPD)
    , m_jumpforce(DEFAULT_JUMP_FORCE)
    , m_hdrag(DEFAULT_HDRAG)
    , m_score(0)
{
    m_shape.setFillColor(DEFAULT_COLOR);
}


Player::Player(std::ifstream& in)
    : GameObj(in)
    , Entity(in)
    , PhysicsObj(in)
    , Solid(in)
{
    in.read((char*) &m_acc, sizeof(m_acc));
    in.read((char*) &m_maxhspd, sizeof(m_maxhspd));
    in.read((char*) &m_jumpforce, sizeof(m_jumpforce));
    in.read((char*) &m_hdrag, sizeof(m_hdrag));
    in.read((char*) &m_score, sizeof(m_score));
    m_shape.setFillColor(DEFAULT_COLOR);
}


void Player::update()
{
    // Use the Physics Object gravity
    PhysicsObj::update();

    // Calculate horizontal speed
    calcHspd();

    // Calculate vertical speed
    calcVspd();

    // Interact with objects
    activateInteractables();

    // Collide with anything horizontally
    hcollide();

    // Collide with anything upwards
    vcollide();

    // Move the player with the calculated speed
    move({ m_hspd, m_vspd });
}


void Player::drawGUI() const
{
    // Text to draw on the screen
    std::string text = "Score: " + std::to_string(m_score);

    // Draw the text
    Game::i().drawGUIText(GUI_SCORE_POS, text, SCORE_TEXT_SIZE, sf::Color::White, sf::Color::Black);
}


void Player::activateInteractables()
{
    // Collision rectangle at the next position
    sf::FloatRect collisionRect(getPosition(), getSize());
    collisionRect.left += m_hspd;
    collisionRect.top += m_vspd;

    // Interact with all the objects in the collision rect
    std::vector<Interactable*> vec = Game::i().checkCollision<Interactable>(collisionRect);
    for (size_t i = 0; i < vec.size(); i++)
        vec[i]->interact(*this);
}


void Player::addScore(size_t points)
{
    m_score += points;
}


void Player::serialize(std::ofstream& file) const
{
    unsigned char id = getSaveId();
    file.write((const char*) &id, sizeof(id));

    PhysicsObj::serialize(file);

    file.write((const char*) &m_acc, sizeof(m_acc));
    file.write((const char*) &m_maxhspd, sizeof(m_maxhspd));
    file.write((const char*) &m_jumpforce, sizeof(m_jumpforce));
    file.write((const char*) &m_hdrag, sizeof(m_hdrag));
    file.write((const char*) &m_score, sizeof(m_score));
}


unsigned char Player::getSaveId()
{
    return ID;
}


void Player::calcHspd()
{
    // Apply acceleration
    if (sf::Keyboard::isKeyPressed(KEY_LEFT))
        m_hspd -= m_acc;

    if (sf::Keyboard::isKeyPressed(KEY_RIGHT))
        m_hspd += m_acc;

    if (m_hspd != 0) {
        // If the player is moving and hasn't pressed a direction key apply drag
        if (!sf::Keyboard::isKeyPressed(KEY_LEFT) && !sf::Keyboard::isKeyPressed(KEY_RIGHT)) {
            float newHspd = m_hspd - (m_hspd > 0 ? 1 : -1) * m_hdrag;

            // If the hspeed hasn't passed 0 due to drag
            if (newHspd * m_hspd > 0)
                m_hspd = newHspd;   // Save the calculated hspd
            else
                m_hspd = 0;         // Set hspd to 0 if drag has caused the player to stop completely
        }

        // Sets the min and max of hspd
        m_hspd = Util::clamp(m_hspd, -m_maxhspd, m_maxhspd);
    }
}


void Player::hcollide()
{
    // No collisions if the horizontal speed is 0
    if (m_hspd == 0)
        return;

    // Create the correct collision rectangle directly
    // next to the player right where he should move to
    sf::FloatRect collisionRect(getPosition(), getSize());
    if (m_hspd > 0) {
        collisionRect.left += collisionRect.width;
        collisionRect.width = m_hspd;
    } else {
        collisionRect.left += m_hspd;
        collisionRect.width = -m_hspd;
    }

    // Get the closest object horizontally that collides with the collision rectangle
    Solid* closest =
        Game::getClosest (
            Game::i().checkCollision<Solid> (collisionRect),
            m_hspd > 0 ? Direction::RIGHT : Direction::LEFT
        );

    // If the object is about to collide with anything solid
    if (closest) {
        // Move right next to the object
        setPosition ({
            closest->getPosition().x + (m_hspd < 0 ? closest->getSize().x : -getSize().x),
            getPosition().y
        });
        m_hspd = 0;
    }
}


void Player::calcVspd()
{
    // Apply jump force if the player is on the ground
    if (m_grounded && sf::Keyboard::isKeyPressed(KEY_JUMP))
        m_vspd = -m_jumpforce;
}


void Player::vcollide()
{
    // If the player is moving upwards
    if (m_vspd < 0) {
        // Create a collision rectangle directly above the
        // player right where the object should move up to
        sf::FloatRect collisionRect (getPosition(), getSize());
        collisionRect.top += m_vspd;
        collisionRect.height = m_vspd;

        // Get the closest object upwards that collides with the collision rectangle
        Solid* closest = Game::getClosest(Game::i().checkCollision<Solid>(collisionRect), Direction::UP);

        // If the object is about to collide with anything solid
        if (closest) {
            m_vspd = 0;
            // Move up to the object
            setPosition ({
                getPosition().x,
                closest->getPosition().y + closest->getSize().y
            });
        }
    }
}
