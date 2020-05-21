#include "PhysicsObj.hpp"
#include "Game.hpp"
#include "Solid.hpp"

PhysicsObj::PhysicsObj(sf::Vector2f pos, sf::Vector2f size, float gravity)
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
        sf::Rect<float> collisionRect (
            { m_position.x, m_position.y + m_size.y },
            { m_size.x, m_vspd + 1}
        );

        // Get all objects that collide with the collision rectangle
        std::vector<Solid*> collisionVector = Game::i().checkCollision<Solid>(collisionRect);

        // If the object is about to collide with anything solid
        if (!collisionVector.empty()) {

            // Stop the object from falling any further
            m_grounded = true;
            m_vspd = 0;

            // New: Find the closest Solid object below this object
            const Solid* closest =
                *std::min_element ( // STL function that returns the minimal element
                    collisionVector.begin(),
                    collisionVector.end(),
                    [](const Solid* obj1, const Solid* obj2) { // Lambda function to compare the objects
                        return obj1->getPosition().y < obj2->getPosition().y;
                    }
                );

            // Move the object on top of that object
            m_position.y = closest->getPosition().y - m_size.y;

        }
    } else {
        // The object is moving upwards -> he's not grounded
        m_grounded = false;
    }

    // Apply the calculated vertical speed
    m_position.y += m_vspd;
}
