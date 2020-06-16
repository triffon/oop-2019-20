#include "Game.hpp"
#include "Solid.hpp"
#include "Pushable.hpp"
#include "PhysicsObj.hpp"

Pushable::Pushable(const sf::Vector2f& pos, const sf::Vector2f& size)
    : Interactable(pos, size)
{}


Pushable::Pushable(std::ifstream& in)
    : Interactable(in)
{}


void Pushable::interact(GameObj& interactor)
{
    if (PhysicsObj* inter = dynamic_cast<PhysicsObj*>(&interactor)) {
        sf::FloatRect collisionRect(getPosition(), getSize());
        if (inter->getHspd() > 0) {
            collisionRect.left += collisionRect.width;
            collisionRect.width = inter->getHspd();
        } else {
            collisionRect.left += inter->getHspd();
            collisionRect.width = -inter->getHspd();
        }

        std::vector<Pushable*> vecP = Game::i().checkCollision<Pushable>(collisionRect);
        Pushable* closestP = Game::i().getClosest(vecP, inter->getHspd() > 0 ? Direction::RIGHT : Direction::LEFT);
        if (closestP)
            closestP->interact(interactor);  // Use the interator's hspd

        std::vector<Solid*> vecS = Game::i().checkCollision<Solid>(collisionRect);
        Solid* closestS = Game::i().getClosest(vecS, inter->getHspd() > 0 ? Direction::RIGHT : Direction::LEFT);
        if (closestS) {
            setPosition ({
                closestS->getPosition().x + (inter->getHspd() < 0 ? closestS->getSize().x : -getSize().x),
                getPosition().y
            });
        } else {
            move({ inter->getHspd(), 0 });
        }
    }
}
