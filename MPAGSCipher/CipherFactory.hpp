#ifndef CIPHERFACTORY_HPP
#define CIPHERFACTORY_HPP

#include <memory>

#include "Cipher.hpp"
#include "CipherType.hpp"

// enum class CipherType{Caesar, Playfair, Vigenere};
// can comment out since in hpp file

std::unique_ptr<Cipher> cipherFactory(const CipherType cipherType,
				      const std::string& key);

#endif
