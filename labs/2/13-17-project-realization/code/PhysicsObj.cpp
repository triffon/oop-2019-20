#include "PhysicsObj.hpp"
#include "Game.hpp"
#include "Solid.hpp"

// Frames before the physics of the object kick in
const size_t DEFAULT_INACTIVE_TIME = 30;

PhysicsObj::PhysicsObj(const sf::Vector2f& pos, const sf::Vector2f& size, float gravity)
    : Entity(pos, size)
    , m_grav(gravity)
    , m_grounded(true)
    , m_inactivity(DEFAULT_INACTIVE_TIME)
{}


PhysicsObj::PhysicsObj(std::ifstream& in)
    : Entity(in)
    , m_inactivity(DEFAULT_INACTIVE_TIME)
{
    in.read((char*) &m_grav, sizeof(m_grav));
    in.read((char*) &m_hspd, sizeof(m_hspd));
    in.read((char*) &m_vspd, sizeof(m_vspd));
    in.read((char*) &m_grounded, sizeof(m_grounded));
}


void PhysicsObj::update()
{
    if (m_inactivity == 0) {
        // If the object isn't grounded apply gravity
        if (!m_grounded)
            m_vspd += m_grav;

        // If the object is moving downwards
        if (m_vspd > 0) {

            // The object is falling -> he's not grounded
            m_grounded = false;

            // Create a collision rectangle directly below the
            // object right where the object should fall to
            sf::Rect<float> collisionRect (getPosition(), getSize());
            collisionRect.top += collisionRect.height;
            collisionRect.height = m_vspd;

            // Get the closest object downwards that collides with the collision rectangle
            Solid* closest = Game::getClosest(Game::i().checkCollision<Solid>(collisionRect), Direction::DOWN);

            // If the object is about to collide with anything solid
            if (closest) {
                // Stop the object from falling any further
                m_grounded = true;
                m_vspd = closest->getPosition().y - getSize().y - getPosition().y;
            }
        } else {
            // The object is moving upwards -> he's not grounded
            m_grounded = false;
        }
    } else {
        --m_inactivity;
    }
}


void PhysicsObj::seriallize(std::ofstream& file) const
{
    Entity::seriallize(file);

    file.write((const char*) &m_grav, sizeof(m_grav));
    file.write((const char*) &m_hspd, sizeof(m_hspd));
    file.write((const char*) &m_vspd, sizeof(m_vspd));
    file.write((const char*) &m_grounded, sizeof(m_grounded));
}
