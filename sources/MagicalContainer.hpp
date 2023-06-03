#include <iostream>
#include <vector>
using namespace std;

namespace ariel {

    class MagicalContainer {
    private:
        vector<int> elements;

    public:
        MagicalContainer();
        void addElement(int);
        int size() const;
        void removeElement(int);
        vector<int> getElements() const;

        class AscendingIterator {
        private:
            MagicalContainer& container;
            int currentIndex;

        public:
            AscendingIterator(MagicalContainer&, int);
            AscendingIterator(MagicalContainer& magicalContainer);
            AscendingIterator(const AscendingIterator& other);

            AscendingIterator() = delete;
            AscendingIterator(AscendingIterator&&) = delete;
            AscendingIterator& operator=(AscendingIterator&&) = delete;

            ~AscendingIterator();
            AscendingIterator& operator=(const AscendingIterator& other);
            bool operator==(const AscendingIterator& other) const;
            bool operator!=(const AscendingIterator& other) const;
            bool operator>(const AscendingIterator& other) const;
            bool operator<(const AscendingIterator& other) const;
            int operator*() const;
            AscendingIterator& operator++();
            AscendingIterator begin() const;
            AscendingIterator end() const;
        };

        class PrimeIterator {
        private:
            MagicalContainer& container;
            int currentIndex;
        public:
            PrimeIterator() = delete;
            PrimeIterator(PrimeIterator&&) = delete;
            PrimeIterator& operator=(PrimeIterator&&) = delete;

            PrimeIterator(MagicalContainer&, int);
            PrimeIterator(MagicalContainer& magicalContainer);
            PrimeIterator(const PrimeIterator& other);
            ~PrimeIterator();
            PrimeIterator& operator=(const PrimeIterator& other);
            bool operator==(const PrimeIterator& other) const;
            bool operator!=(const PrimeIterator& other) const;
            bool operator>(const PrimeIterator& other) const;
            bool operator<(const PrimeIterator& other) const;
            int operator*() const;
            PrimeIterator& operator++();
            PrimeIterator begin() const;
            PrimeIterator end() const;
        };

        class SideCrossIterator {
        private:
            MagicalContainer& container;
            int currentIndex;

        public:
            SideCrossIterator() = delete;
            SideCrossIterator(SideCrossIterator&&) = delete;
            SideCrossIterator& operator=(SideCrossIterator&&) = delete;

            SideCrossIterator(MagicalContainer&, int);
            SideCrossIterator(MagicalContainer& magicalContainer);
            SideCrossIterator(const SideCrossIterator& other);
            ~SideCrossIterator();
            SideCrossIterator& operator=(const SideCrossIterator& other);
            bool operator==(const SideCrossIterator& other) const;
            bool operator!=(const SideCrossIterator& other) const;
            bool operator>(const SideCrossIterator& other) const;
            bool operator<(const SideCrossIterator& other) const;
            int operator*() const;
            SideCrossIterator& operator++();
            SideCrossIterator begin() const;
            SideCrossIterator end() const;
        };


    };
}
