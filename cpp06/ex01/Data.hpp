#pragma once

struct Data {
	private:
		int value;

	public:
		Data(void);
		~Data(void);
		Data(const Data& other);
		Data& operator=(const Data& other);
		int getValue(void) const;
};
