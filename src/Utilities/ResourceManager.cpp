#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"
//-----------------------------------------------------------------------------------------------------------
ResourceManager ResourceManager::m_instance = ResourceManager();
//-----------------------------------------------------------------------------------------------------------
ResourceManager::ResourceManager() {

	if (!m_font.loadFromFile(FONT))
	{
		throw (std::runtime_error("Could not open font"));
	}
};
//-----------------------------------------------------------------------------------------------------------
ResourceManager& ResourceManager::instance()
{
	return m_instance;
}
//-----------------------------------------------------------------------------------------------------------
const sf::Font& ResourceManager::getFont() const
{
	return m_font;
}
//-----------------------------------------------------------------------------------------------------------
void ResourceManager::playSound(const std::string soundName)
{
	m_sound.setBuffer(getSound(soundName));
	m_sound.play();
}
//-----------------------------------------------------------------------------------------------------------
sf::SoundBuffer& ResourceManager::getSound(std::string soundName)
{
	if (m_sounds.find(soundName) != m_sounds.end()) { // if the texture exist return it 
		return m_sounds[soundName];
	}
	// else create and store in the hashing table 
	sf::SoundBuffer soundBuffer;
	if (soundBuffer.loadFromFile(soundName))
	{
		m_sounds[soundName] = soundBuffer;
		return m_sounds[soundName];
	}
	throw (std::runtime_error("Could not open sound"));
	
	
}
//-----------------------------------------------------------------------------------------------------------
//texture name is the key to the hashing table and the texture is the value to store
sf::Texture& ResourceManager::getTexture(std::string textureName) // use hash table to store all the textures 
{
	if (m_textures.find(textureName) != m_textures.end()) { // if the texture exist return it 
		return m_textures[textureName];
	}
	// else create and store in the hashing table 
	sf::Texture texutre;
	if(texutre.loadFromFile(textureName))
	{
		m_textures[textureName] = texutre;
		return m_textures[textureName];
	}
	throw (std::runtime_error("Could not open image"));
	
}
//-----------------------------------------------------------------------------------------------------------