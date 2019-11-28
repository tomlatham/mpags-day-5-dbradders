#include <string>
#include <algorithm>
#include "VigenereCipher.hpp"
#include "Alphabet.hpp"
#include "CaesarCipher.hpp"

void VigenereCipher::setKey(const std::string& key)
{
  // Store the key
  key_ = key;

  // Make sure the key is uppercase
 std::transform( std::begin(key_), std::end(key_), std::begin(key_), ::toupper );

  // Remove non-alphabet characters
 key_.erase( std::remove_if( std::begin(key_), std::end(key_), [](char c){ return !std::isalpha(c); } ),
              std::end(key_) );

  // Check if the key is empty and replace with default if so
 if (key_.empty())
   {
     key_ = "KEY";
   }

  // Loop over the key
 for (std::string::size_type i{0}; i < key_.size(); ++i){
   
  // Find the letter position in the alphabet
   auto letterPos = Alphabet::alphabet.find(key_[i]);

  // Create a CaesarCipher using this position as a key
   CaesarCipher caesarCipher { letterPos };

  // Insert a std::pair of the letter and CaesarCipher into the lookup
   charLookup_.insert(std::make_pair(key_[i], caesarCipher));
 }
}

VigenereCipher::VigenereCipher(const std::string& key)
{
  // Set the given key
  setKey(key);
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
					 const CipherMode cipherMode) const
{
  std::string outputText;

  // For each letter in input:
  for (std::string::size_type i{0}; i<inputText.size(); ++i){

  // Find the corresponding letter in the key,
  // repeating/truncating as required
    char keyLetter = key_[i % key_.size()];

  // Find the Caesar cipher from lookup
    const CaesarCipher& cipher { charLookup_.at(keyLetter) };

  // Run the (de)encryption
    outputText += cipher.applyCipher( std::string{inputText[i]}, cipherMode);
  }
    
  // Add the result to the output
  
  return outputText;
}

  
