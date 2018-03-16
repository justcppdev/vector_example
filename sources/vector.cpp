#include <algorithm>
#include <cassert>

class vector_t
{
private:
	int * elements_;
	std::size_t size_;
	std::size_t capacity_;
public:
	vector_t();
	vector_t(vector_t const & other);
	vector_t & operator =(vector_t const & other);
	~vector_t();

	std::size_t size() const;
	std::size_t capacity() const;

	void push_back(int value);
	void pop_back();

	int & operator [](std::size_t index);
	int operator [](std::size_t index) const;

	bool operator ==(vector_t const & other) const;
};

vector_t::vector_t()
{
	int * elements_ = nullptr;
	std::size_t size_ = 0;
	std::size_t capacity_ = 1;
}

vector_t::vector_t(vector_t const & other)
{
	size_ = other.size_;
	capacity_= other.capacity;
	elements_ = new int [capacity_];
	for (std::size_t i = 0; i < size_; ++i)
	{
			elements_[i] = other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	if (this != &other)
	{
		delete[] elements_;
		size_ = other.size;
		capacity_ = other.capacity_;
		elements_ = new int[other.capacity_];
		for (std::size_t i = 0; i < size_; i++) 
		{
			elements_[i] = other.elements_[i];
		}
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if (size_ != other.size_) 
	{
		for (std::size_t i = 0; i < size_; i++) 
		{
			if (elements_[i] != other.elements_[i]) 
			{
				return false;
			}
		}
		return true;
	}
	else return false;
}

vector_t::~vector_t()
{
	delete[] elements_;
	capacity_ = 1;
	size_ = 0;
}

std::size_t vector_t::size() const
{
	return 0;
}

std::size_t vector_t::capacity() const
{
	return 0;
}

void vector_t::push_back(int value)
{
	if (size_ = 0) 
	{
		size_ = 1;
		capacity_ = 1;
		elements_ = new int[capacity_];
		elements_[0] = value;
	}
	else if (size_ == capacity_) 
	{
		int * mas;
		mas = new int[size_];
		for (std::size_t i = 0; i < size_; i++) 
		{
			mas[i] = elements_[i];
		}
		delete [] elements_; 
		capacity_ *= 2;
		elements_ = new int [capacity_];
		
		for (std::size_t i = 0; i < size_; i++)
		{
			elements_[i] = mas[i];
		}
		delete[] mas;
		size_++;
		elements_[size_] = value;
	}
	else 
	{
		size_++;
		elements_[size_] = value;
	}
}

void vector_t::pop_back()
{
	size_--;
	if (size_== 0 || size_ * 4 == capacity_) 
	{
		int *mas;
		mas = new int[size_];
		for (std::size_t i = 0; i < size_; i++)
		{
			mas[i] = elements_[i];
		}
		delete[] elements_;
		capacity_ = capacity_/2;
		elements_ = new int[capacity_];
		for (std::size_t i = 0; i < size_; i++)
		{
			elements_[i] = mas[i];
		}
		delete[] mas;
	}
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	if (lhs == rhs)
	{
		return false;
	}
	return true;
}

vector_t::~vector_t()
{
	delete[] elements_;
	capacity_ = 1;
	size_ = 0;
}


int main()
{
    return 0;
}

