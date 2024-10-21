#ifndef SENECA_CANISTER_H
#define SENECA_CANISTER_H
#include <iostream>
namespace seneca {
   class Canister {
      char* m_contentName;
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs

      /// <summary>
      /// renders the canister unusable by freeing the conent name memory and setting diamieter and height to -1
      /// </summary>
      void setToUnusable();
      /// <summary>
      /// Returns true if canister volume is below 0.00001
      /// </summary>
      /// <returns>true if the canister is emtpy</returns>
      bool isEmpty()const;
      /// <summary>
      /// Returns true if height and diameters are within accepable values
      /// </summary>
      /// <returns>true if canister is usable</returns>
      bool usable()const;
      /// <summary>
      /// Returns true if the conent name of the two canisters are the same
      /// </summary>
      /// <param name="C">const Canister& to compare to</param>
      /// <returns>True if the name is the same</returns>
      bool hasSameContent(const Canister& C)const;
      /// <summary>
      /// returns the capacity of the canister
      /// </summary>
      /// <returns>Capacity of Canister</returns>
      double capacity()const;
      /// <summary>
      /// Returns the content volume. Always less than capacity
      /// </summary>
      /// <returns>Conent Volume</returns>
      double volume()const;
   public:
      //Constructors
       Canister();
       Canister(const char* contentName); //One-argument constructor
       //Three-arguments constructor
       Canister(double height, double diameter, const char* contentName = nullptr); 
    
       //Destructor
       ~Canister();

       // Clears the canister to an empty state
       Canister& clear();
       // Sets the content name of the canister
       Canister& setContent(const char* contentName);
       // Adds a quantity of liquid to the canister
       Canister& pour(double quantity);
       // Pours contents from another canister
       Canister& pour(Canister& can);

       std::ostream& display()const;
   };
}

#endif // !SENECA_BOX_H
