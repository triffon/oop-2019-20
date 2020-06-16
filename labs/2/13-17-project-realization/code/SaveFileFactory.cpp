#include "SaveFileFactory.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "Button.hpp"
#include "Crate.hpp"
#include "Coin.hpp"
#include "Door.hpp"

SaveFileFactory::SaveFileFactory(std::ifstream& file)
    : FileFactory(file)
{}


GameObj* SaveFileFactory::createObj()
{
    unsigned char id;
    m_file.read((char*) &id, sizeof(id));

    if (m_file.eof())
        return nullptr;

    if (id == Player::getSaveId())
        return new (std::nothrow) Player(m_file);
    else if (id == Platform::getSaveId())
        return new (std::nothrow) Platform(m_file);
    else if (id == Crate::getSaveId())
        return new (std::nothrow) Crate(m_file);
    else if (id == Coin::getSaveId())
        return new (std::nothrow) Coin(m_file);
    else if (id == Door::getSaveId())
        return new (std::nothrow) Door(m_file);
    else if (id == Button::getSaveId())
        return new (std::nothrow) Button(m_file);

    return nullptr;
}
