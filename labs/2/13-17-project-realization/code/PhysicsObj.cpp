#include "PhysicsObj.hpp"
#include "Game.hpp"
#include "Solid.hpp"

PhysicsObj::PhysicsObj(const sf::Vector2f& pos, const sf::Vector2f& size, float gravity)
    : Entity(pos, size)
    , m_grav(gravity)
    , m_hspd(0)
    , m_vspd(0)
    , m_grounded(true)
{}


PhysicsObj::PhysicsObj(std::ifstream& in)
    : Entity(in)
{
    in.read((char*) &m_grav, sizeof(m_grav));
    in.read((char*) &m_hspd, sizeof(m_hspd));
    in.read((char*) &m_vspd, sizeof(m_vspd));
    in.read((char*) &m_grounded, sizeof(m_grounded));
}


void PhysicsObj::update()
{
    // If the object isn't grounded apply gravity
    if (!m_grounded)
        m_vspd += m_grav;

    // If the object is moving downwards
    if (m_vspd > 0) {

        // The object is falling -> he's not grounded
        m_grounded = false;

        // Create a collision rectangle directly below the
        // object right where the object should fall to
        sf::FloatRect collisionRect (getPosition(), getSize());
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
}


void PhysicsObj::serialize(std::ofstream& file) const
{
    Entity::serialize(file);

    file.write((const char*) &m_grav, sizeof(m_grav));
    file.write((const char*) &m_hspd, sizeof(m_hspd));
    file.write((const char*) &m_vspd, sizeof(m_vspd));
    file.write((const char*) &m_grounded, sizeof(m_grounded));
}
