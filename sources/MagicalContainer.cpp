#include "MagicalContainer.hpp"


#include <algorithm>

namespace ariel{

    bool isPrime(int num) {
        if (num <= 1)
            return false;
        if (num == 2)
            return true;
        if (num % 2 == 0)
            return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0)
                return false;
        }
        return true;
    }



    MagicalContainer::MagicalContainer() {
    }


    void MagicalContainer::addElement(int element) {
        elements.push_back(element);
        std::sort(elements.begin(), elements.end());
    }


    void MagicalContainer::removeElement(int element) {
        for (auto it = elements.begin(); it != elements.end(); ++it) {
            if (*it == element) {
                elements.erase(it);
                return;
            }
        }
        throw std::runtime_error("the element is not exist");
    }


    int MagicalContainer::size() const {
        return elements.size();
    }


    vector<int> MagicalContainer::getElements() const{
        return elements;
    }




    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& cont, int curr)
            : container(cont), currentIndex(curr) {}


    MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer& magicalContainer) : container(magicalContainer), currentIndex(0) {}


    MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other) : container(other.container), currentIndex(other.currentIndex) {}


    MagicalContainer::AscendingIterator::~AscendingIterator() {}


    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
        if (&container != &other.container) {
            throw runtime_error("iterators all ready assigned");
        }
        if (this != &other) {
            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }


    bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
        return &container == &other.container && currentIndex == other.currentIndex;
    }


    bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
        return !(*this == other);
    }


    bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
        return currentIndex > other.currentIndex;
    }


    bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
        return currentIndex < other.currentIndex;
    }


    int MagicalContainer::AscendingIterator::operator*() const {
        return container.getElements().at((std::vector<int>::size_type)currentIndex);
    }


    MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
        if (currentIndex >= container.getElements().size() || *this == end()) {
            throw runtime_error("iterator out of range");
        }
        currentIndex++;
        return *this;
    }


    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() const {
        return AscendingIterator(container, 0);
    }


    MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() const {
        return AscendingIterator(container, container.size());
    }




    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& cont, int index)
            : container(cont), currentIndex(index) {}


    MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer& magicalContainer)
            : container(magicalContainer), currentIndex(0) {}


    MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
            : container(other.container), currentIndex(other.currentIndex) {}


    MagicalContainer::SideCrossIterator::~SideCrossIterator() {}


    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
        if (&container != &other.container) {
            throw runtime_error("iterators all ready assigned");
        }
        if (this != &other) {
            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }


    bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
        return currentIndex == other.currentIndex && &container == &other.container;
    }


    bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
        return !(*this == other);
    }


    bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
        return currentIndex > other.currentIndex;
    }


    bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
        return currentIndex < other.currentIndex;
    }


    int MagicalContainer::SideCrossIterator::operator*() const {
        if (!(currentIndex % 2)) {
            return container.elements.at((std::vector<int>::size_type)(currentIndex / 2));
        } else {
            return container.elements.at((std::vector<int>::size_type)(container.size() - 1 - (currentIndex - 1) / 2));
        }
    }


    MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
        if (currentIndex >= container.getElements().size() || *this == end()) {
            throw runtime_error("iterator out of range");
        }
        currentIndex++;
        return *this;
    }


    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() const {
        return SideCrossIterator(container, 0);
    }


    MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() const {
        return SideCrossIterator(container, container.size());
    }



    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& cont, int curr)
            : container(cont), currentIndex(curr) {

        while (currentIndex < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)currentIndex))) {
            currentIndex++;
        }
    }


    MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& magicalContainer)
            : container(magicalContainer), currentIndex(0) {

        while (currentIndex < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)currentIndex))) {
            currentIndex++;
        }
    }


    MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
            : container(other.container), currentIndex(other.currentIndex) {}


    MagicalContainer::PrimeIterator::~PrimeIterator() {}


    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
        if (&container != &other.container) {
            throw runtime_error("iterators all ready assigned ");
        }
        if (this != &other) {
            container = other.container;
            currentIndex = other.currentIndex;
        }
        return *this;
    }


    bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
        return &container == &other.container && currentIndex == other.currentIndex;
    }


    bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
        return !(*this == other);
    }


    bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
        return currentIndex > other.currentIndex;
    }


    bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
        return currentIndex < other.currentIndex;
    }


    int MagicalContainer::PrimeIterator::operator*() const {
        return container.getElements().at((std::vector<int>::size_type)currentIndex);
    }


    MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
        if (currentIndex >= container.getElements().size() || *this == end()) {
            throw runtime_error("iterator out of range");
        }
        currentIndex++;
        while (currentIndex < container.size() && !isPrime(container.getElements().at((std::vector<int>::size_type)currentIndex))) {
            currentIndex++;
        }
        return *this;
    }


    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() const {
        return PrimeIterator(container, 0);
    }

    MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() const {
        return PrimeIterator(container, container.size());
    }

}
