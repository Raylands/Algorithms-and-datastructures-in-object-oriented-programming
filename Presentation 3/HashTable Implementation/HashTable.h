#include <list>
#include <vector>
#include <string>

using namespace std;
template <typename K, typename V>
class Entry {	// a (key, value) pair
public: 
	Entry(const K& k = K(), const V& v = V())	// constructor
		: _key(k), _value(v) { ; }
	const K& key() const { return _key; }		// get key
	const V& value() const { return _value; }	// get value
	void setKey(const K& k) { _key = k; }		// set key
	void setValue(const V& v) { _value = v; }	// set value
	Entry<K, V> operator=(Entry<K, V> E) { setKey(E.key()); setValue(E._value); return *this; } // set entry
private: 
	K _key;		// key
	V _value;	// value
};

template <typename K, typename V, typename H>
class HashTable {
public:						
	typedef Entry< K, V> Entry;			// a (key,value) pair
	class Iterator;						// a iterator/position
public:						
	HashTable(int capacity = 100);		// constructor
	int size() const;					// number of entries
	bool empty() const;					// is the map empty?
	Iterator find(const K& k);			// find entry with key k
	Iterator put(const K& k, const V& v);	// insert/replace (k,v)
	void erase(const K& k);				// remove entry with key k
	void erase(const Iterator& p);		// erase entry at p
	Iterator begin();					// iterator to first entry
	Iterator end();						// iterator to end entry
protected:							
	typedef std::list<Entry> Bucket;			// a bucket of entries
	typedef std::vector<Bucket> BktArray;		// a bucket array

	Iterator finder(const K& k);					// find utility
	Iterator inserter(const Iterator& p, const Entry& e);   // insert utility
	void eraser(const Iterator& p);					// remove utility
	typedef typename BktArray::iterator BItor;	    // bucket iterator
	typedef typename Bucket::iterator EItor;	    // entry iterator
	static void nextEntry(Iterator& p)			    // bucket's next entry
	{
		++p.ent;
	}
	static bool endOfBkt(const Iterator& p)		    // check for end of bucket
	{
		return p.ent == p.bkt->end();
	}												
private:
	int n;						// number of entries
	H hash;						// the hash comparator
	BktArray B;					// bucket array
public:							
	class Iterator {       		// an iterator (& position)
	private:
		EItor ent;				// which entry
		BItor bkt;				// which bucket
		const BktArray* ba;		// which bucket array
	public:
		Iterator(const BktArray& a, const BItor& b, const EItor& q = EItor())
			: ent(q), bkt(b), ba(&a) { }
		Entry& operator*() const;			// get entry
		bool operator==(const Iterator& p) const;		// are iterators equal?
		Iterator& operator++();				// advance to next entry
		friend class HashTable;				// give HashTable access
	};					
};

class CycleShiftHash {
public:
	int operator()(string s) {
		int h = 0;
		for (int i = 0; i < s.length(); i++) {
			h = (h << 5) | (h >> 27);   // 5-bit cyclic shift of the running sum
			h += (int)s[i];				// add character
		}
		return h;
	}
};

