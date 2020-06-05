#include "SaveFileFactory.hpp"
#include "Platform.hpp"
#include "Player.hpp"
#include "Crate.hpp"
#include "Coin.hpp"

SaveFileFactory::SaveFileFactory(std::ifstream& file)
    : FileFactory(file)
{}


GameObj* SaveFileFactory::createObj() const
{
    size_t id;
    m_file.read((char*) &id, sizeof(id));

    if (m_file.eof())
        return nullptr;

    if (id == Player::getSaveId())
        return new Player(m_file);
    else if (id == Platform::getSaveId())
        return new Platform(m_file);
    else if (id == Crate::getSaveId())
        return new Crate(m_file);
    else if (id == Coin::getSaveId())
        return new Coin(m_file);

    return nullptr;
}
