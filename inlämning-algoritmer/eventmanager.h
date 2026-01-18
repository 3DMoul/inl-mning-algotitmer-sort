#pragma once
#include "iostream"
#include "string"
enum class eventType { TemperatureReading = 1, ButtonPress = 2, MotionRecord = 3};

class Event
{
public:
	Event(eventType type, std::string UnitOfMeasurment, std::string SensorName, double MinSimulation, double MaxSimulation);
	virtual ~Event() = default;
	virtual double Read() const;
	std::string name() const;
	double minValue() const;
	double maxValue() const;
	std::string GetUnitOfMeasurment() const;
	eventType eventType()const;
private:
	int timestamp;
	int sensorId;
	int value;
	eventType type;
};

namespace eventType
{
	class TemperatureReading : public Event
	{
	public:
		TemperatureReading(std::string NewName, double MinSimulation, double MaxSimulation);
		//har get denna för att airquality behöver inte decimaler i sina measurments
		double Read() const override;
	};
	class ButtonPress : public Event
	{
	public:
		ButtonPress(std::string NewName, double MinSimulation, double MaxSimulation);
		//denna ger measurment med decimaler
		double Read() const override;
	};
	class MotionRecord : public Event
	{
	public:
		MotionRecord(std::string NewName, double MinSimulation, double MaxSimulation);
		//har get denna för att Humidity behöver inte decimaler i sina measurments
		double Read() const override;
	};
}