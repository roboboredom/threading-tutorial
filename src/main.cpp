
/* Generates std::string of random chars, of size_t length. */
std::string random_string(size_t length)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ std::rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}


template<typename T> // see: Curiously Recurring Template Pattern
class CUniqueKeyRegistry
{
public:
  /* adds new value at unique id, returns the unique id */
  int register(std::string value)
  {
    mRegistry[T::iKeyCounter++] = value;
    return T::iKeyCounter;
  }

  /* returns true if key exists */
  bool isRegistered(int key) { return T::mRegistry.count(key); } // count() only returns 0 or 1

  /* returns value at key */
  std::string getValue(int key) { return T::mRegistry[key]; }

  // /* returns the full registry std::map */
  // static const std::map<int, std::string>& getRegistry() { return mRegistry; }

private:
  /* std::map registry of keys (int) to values (std::string) */
  std::map<int, std::string> mRegistry;

  /* key incrementor */
  int iKeyCounter;
};
//template<typename T> std::map<int, std::string> CUniqueKeyRegistry<T>::mRegistry;
template<typename T> int CUniqueKeyRegistry<T>::iKeyCounter = 0;


class FruitRegistry : public CUniqueKeyRegistry<FruitRegistry> {};
FruitRegistry::register("apple");
FruitRegistry::register("pear");
FruitRegistry::register("melon");
FruitRegistry::register("orange");

int main()
{
  // register some random keys at runtime
  for (int i = 0; i < 10; i++)
  {
    FruitRegistry::register(random_string(8));
  }

  // request a ton of possible keys, print if they exist and if so their value
  for (int key = 0; key < 20; key++)
  {
    if (FruitRegistry::isRegistered(key))
    {
      std::cout << "valid key: " << key << " = value: " << FruitRegistry::getValue(key) << "\n";
    }
    else
    {
      std::cout << "invalid key: " << key << "\n";
    }
  }

  
  return 0;
}