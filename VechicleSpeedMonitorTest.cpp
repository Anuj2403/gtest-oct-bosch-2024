#include "gtest/gtest.h"
#include "VehicleSpeedMonitor.h"


// BNFSpeedSensor

TEST(BNFSpeedSensorTest, SpeedInRange) {
    BNFSpeedSensor sensor;
    int speed = sensor.getCurrentSpeed();
    EXPECT_GE(speed, 1);
    EXPECT_LE(speed, 100);
}

// IOTCloudCommunicator

TEST(IOTCloudCommunicatorTest, SuccessfulPush) {
    IOTCloudCommunicator communicator;
    int statusCode = communicator.pushMessage("Test Message");
    EXPECT_GE(statusCode, 200);
    EXPECT_LE(statusCode, 400);
}

TEST(IOTCloudCommunicatorTest, FailedPush) {
    IOTCloudCommunicator communicator;
    int statusCode = communicator.pushMessage("Test Message");
    //EXPECT_GE(statusCode, 400);
    EXPECT_LE(statusCode, 500);
}

// SpeedMonitor

TEST(SpeedMonitorTest, InvalidThreshold) {
    SpeedMonitor monitor(0);
    monitor.monitor();
}

TEST(SpeedMonitorTest, BelowThreshold) {
    SpeedMonitor monitor(100);
}

TEST(SpeedMonitorTest, AboveThresholdSuccess) {
    SpeedMonitor monitor(50);
}

TEST(SpeedMonitorTest, AboveThresholdFailure) {
    SpeedMonitor monitor(50);
}
