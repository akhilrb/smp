class Classy
{
	private:
		uint8_t pin;
		unsigned long prevChange = 0;
		uint16_t offTime = 20;
		bool state = false;
	public:
		// constructor
		Classy(uint8_t _pin)
		{
			pin = _pin;
			prevChange = millis();
			pinMode(pin, OUTPUT);
		}

		void update()
		{
			if(!state && millis() - prevChange >= offTime)
			{
				state = true;
				digitalWrite(pin, HIGH);
				prevChange = millis();
			}
			if(state && millis() - prevChange >= 1)
			{
				state = false;
				digitalWrite(pin, LOW);
				prevChange = millis();
			}
		}

		void setOffTime(uint16_t _offTime)
		{
			offTime = _offTime;
		}
};