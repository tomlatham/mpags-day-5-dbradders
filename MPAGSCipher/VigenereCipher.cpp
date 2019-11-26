#include <string>
#include "VigenereCipher.hpp"

void VigenereCipher::setKey(const std::string& key)
{

}

VigenereCipher::VigenereCipher(const std::string& key)
{
  // Set the given key
  setKet(key);
}

std::string VignenereCipher::applyCipher(const std::string& inputText,
					 const CipherMode /*cipherMode*/) const
{
  return inputText;
}

  
