#include <memory>
#include "CipherFactory.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType cipherType,
				      const std::string& key)
{
  switch (cipherType){

  case CipherType::Caesar :
    return std::make_unique<CaesarCipher>(key);
  case CipherType::Playfair :
    return std::make_unique<PlayfairCipher>(key);
  case CipherType::Vigenere :
    return std::make_unique<VigenereCipher>(key);
  }
}


