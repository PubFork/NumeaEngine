#ifndef NU_TIME_HPP
#define NU_TIME_HPP

#include "Prerequisites.hpp"
#include "String.hpp"

namespace nu
{

class Time
{
	public:
		static const I64 NanosecondsPerTick = 100;
		static const I64 TicksPerMicrosecond = 10;
		static const I64 TicksPerMillisecond = 10000;
		static const I64 TicksPerSecond = 10000000;
		static const I64 TicksPerMinute = 600000000;
		static const I64 TicksPerHour = 36000000000;
		static const I64 TicksPerDay = 864000000000;
		static const I64 TicksPerWeek = 6048000000000;

		static const Time Zero;
		static const Time Second;

	public:
		Time();
		Time(I64 ticks);
		Time(I32 hours, I32 minutes, I32 seconds);
		Time(I32 days, I32 hours, I32 minutes, I32 seconds);
		Time(I32 days, I32 hours, I32 minutes, I32 seconds, I32 milliseconds, I32 microseconds = 0);

		Time& set(I64 ticks);
		Time& set(I32 hours, I32 minutes, I32 seconds);
		Time& set(I32 days, I32 hours, I32 minutes, I32 seconds);
		Time& set(I32 days, I32 hours, I32 minutes, I32 seconds, I32 milliseconds, I32 microseconds = 0);

		Time operator+(const Time& time) const;
		Time& operator+=(const Time& time);
		Time operator-() const;
		Time operator-(const Time& time) const;
		Time& operator-=(const Time& time);
		Time operator*(F32 scalar) const;
		Time& operator*=(F32 scalar);
		Time operator/(F32 scalar) const;
		Time& operator/=(F32 scalar);
		Time operator%(const Time& time) const;
		Time& operator%=(const Time& time);

		bool operator==(const Time& time) const;
		bool operator!=(const Time& time) const;
		bool operator>(const Time& time) const;
		bool operator>=(const Time& time) const;
		bool operator<(const Time& time) const;
		bool operator<=(const Time& time) const;
		bool isZero() const;

		Time getDuration() const;
		I32 getDays() const;
		I32 getHours() const;
		I32 getMinutes() const;
		I32 getSeconds() const;
		I32 getMilliseconds() const;
		I32 getMicroseconds() const;
		I64 getTicks() const;

		F32 asSeconds() const;
		I32 asMilliseconds() const;
		I64 asMicroseconds() const;

		static Time now();

	private:
		I64 mTicks;
};

inline Time operator*(F32 scalar, const Time& time)
{
	return time.operator*(scalar);
}

template <> inline std::string toString<Time>(const Time& value)
{
	return std::string(); // TODO : toString<Time>()
}

template <> inline Time fromString<Time>(const std::string& value)
{
	return Time(); // TODO : fromString<Time>()
}	

Time days(I32 amount);
Time hours(I32 amount);
Time minutes(I32 amount);
Time seconds(F32 amount);
Time milliseconds(I32 amount);
Time microseconds(I64 amount);

class Clock
{
	public:
		Clock();

		Time getElapsedTime() const;
		Time restart();

	private:
		Time mStart;
};

} // namespace nu

#endif // NU_TIME_HPP