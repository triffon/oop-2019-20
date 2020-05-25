#include "PhysicsObj.hpp"
#include "Game.hpp"
#include "Solid.hpp"

PhysicsObj::PhysicsObj(const sf::Vector2f& pos, const sf::Vector2f& size, float gravity)
    : Entity(pos, size)
    , m_grav(gravity)
    , m_grounded(false)
{}


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
        sf::Rect<float> collisionRect (getPosition(), getSize());
        collisionRect.top += collisionRect.height;
        collisionRect.height = m_vspd;

        // Get the closest object downwards that collides with the collision rectangle
        Solid* closest = Game::getClosest(Game::i().checkCollision<Solid>(collisionRect), Direction::DOWN);

        // If the object is about to collide with anything solid
        if (closest) {
            // Stop the object from falling any further
            m_grounded = true;
            m_vspd = 0;

            // Move the object on top of that object
            setPosition({ getPosition().x, closest->getPosition().y - getSize().y });
        }
    } else {
        // The object is moving upwards -> he's not grounded
        m_grounded = false;
    }
}
