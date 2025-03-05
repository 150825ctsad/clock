#ifndef __GETTIME_H__
#define __GETTIME_H__
#include <Arduino.h>
#include <time.h>
#include <WiFi.h>

#pragma once

tm getTime(); // 修改函数声明为返回时间结构体
void wifi_init(); // 添加wifi初始化函数声明

#endif