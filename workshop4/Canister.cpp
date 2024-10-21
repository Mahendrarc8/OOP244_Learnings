#include <istream>
#include "cstr.h"  
#include "Canister.h"
using namespace std;
namespace seneca {

   const double PI = 3.14159265;
   

   bool Canister::isEmpty() const {
      return m_contentVolume < 0.00001;
   }

   bool Canister::usable() const
   {
      return m_height >= 10 && m_height <= 40 && m_diameter >= 10 && m_diameter <= 30;
   }

   void Canister::setToUnusable(){
      freeMem(m_contentName);
      m_diameter = m_height = -1.0;
   }

   double Canister::capacity() const {
      return PI * (m_height-0.267) * (m_diameter/2) * (m_diameter / 2);
   }

      bool Canister::hasSameContent(const Canister& C)const {
      return m_contentName && C.m_contentName && strcmp(m_contentName, C.m_contentName) == 0;
   }

   double Canister::volume() const {
      return m_contentVolume;
   }

   // Default constructor initializes canister with default values
   Canister::Canister() {
       m_contentName = nullptr; // No content name assigned
       m_diameter = 10.0; // Default diameter
       m_height = 13.0; // Default height
       m_contentVolume = 0.0; // Initial volume
   }

   // Constructor that initializes canister with a specific content name
   Canister::Canister(const char* contentName) {
       m_contentName = nullptr; // No content name assigned initially
       m_diameter = 10.0; // Default diameter
       m_height = 13.0; // Default height
       m_contentVolume = 0.0; // Initial volume
       alocpy(this->m_contentName, contentName); // Allocate memory for the content name
   }

   // Constructor that sets height, diameter, and content name if usable
   Canister::Canister(double height, double diameter, const char* contentName) {
       m_contentName = nullptr; // No content name initially
       m_contentVolume = 0; // Initial volume
       m_height = height; // Set height
       m_diameter = diameter; // Set diameter
       if (usable()) { // Check if dimensions are usable
           alocpy(this->m_contentName, contentName); // Allocate memory for content name
       }
   }

   // Destructor to clean up allocated memory
   Canister::~Canister() {
       freeMem(m_contentName); // Free memory for content name
   }

   // Clear the content of the canister and reset the volume to zero
   Canister& Canister::clear() {
       freeMem(m_contentName); // Free content name memory
       m_contentVolume = 0.0; // Reset volume
       return *this; // Enable method chaining
   }

   // Set or update the canister's content name
   Canister& Canister::setContent(const char* contentName) {
       // Check if the content name is not empty and the canister is usable
       if (strlen(contentName) != 0 && usable()) {
           // If the canister is empty or has no content, allocate new memory for content name
           if (m_contentName == nullptr || isEmpty()) {
               alocpy(m_contentName, contentName);
           }
           // If the content is different and not empty, mark canister as unusable
           else if (!hasSameContent(contentName)) {
               setToUnusable();
           }
       }
       return *this; // Enable method chaining
   }

   // Add a specified quantity of content to the canister
   Canister& Canister::pour(double quantity) {
       if (usable()) { // Check if the canister is usable
           // Only add quantity if it doesn't exceed capacity
           if (quantity > 0 && quantity + volume() <= capacity()) {
               m_contentVolume += quantity; // Increase content volume
           }
           else {
               setToUnusable(); // Mark as unusable if it exceeds capacity
           }
       }
       return *this; // Enable method chaining
   }

   // Transfer content from another canister to this canister
   Canister& Canister::pour(Canister& can) {
       if (usable()) { // Check if this canister is usable
           double spaceLeft = capacity() - volume(); // Calculate available space
           if (can.volume() > spaceLeft) { // Check if the other canister has more volume than available space
               can.m_contentVolume -= spaceLeft; // Reduce the volume from the other canister
               m_contentVolume = capacity(); // Fill this canister to capacity
           }
           else {
               pour(can.volume()); // Pour the remaining volume
               can.m_contentVolume = 0.0; // Empty the other canister
           }
           setContent(can.m_contentName); // Update content name
       }
       return *this; // Enable method chaining
   }

   std::ostream& Canister::display() const 
   {
      cout.setf(ios::fixed);
      cout.precision(1);
      cout.width(7);
      cout << capacity() << "cc (";
      cout.width(4);
      cout << m_height << "x";
      cout.width(4);
      cout << m_diameter << ") Canister";
      if (!usable()) {
         cout << " is  Unusable   recycle!";
      }
      else {
         cout << " of ";
         cout.width(7);
         cout << volume() << "cc   " << (m_contentName?m_contentName:"Sanetized and Empty");
      }
      return cout;
   }
}