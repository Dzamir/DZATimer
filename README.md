# DZATimer

A small timer class.

The timer continues to track the elapsed time even when the application is in background.

You can also init the timer with a delegate, and the timer will send an event after every timestep.

[![CI Status](http://img.shields.io/travis/Davide Di Stefano/DZATimer.svg?style=flat)](https://travis-ci.org/Davide Di Stefano/DZATimer)
[![Version](https://img.shields.io/cocoapods/v/DZATimer.svg?style=flat)](http://cocoapods.org/pods/DZATimer)
[![License](https://img.shields.io/cocoapods/l/DZATimer.svg?style=flat)](http://cocoapods.org/pods/DZATimer)
[![Platform](https://img.shields.io/cocoapods/p/DZATimer.svg?style=flat)](http://cocoapods.org/pods/DZATimer)

## Usage

To run the example project, clone the repo, and run `pod install` from the Example directory first.

	DZATimer * timer = [[DZATimer alloc] initWithDelegate:nil];
	[timer startTimer];
	sleep(1);
	[timer pauseTimer];
	sleep(1);
	[timer startTimer];
	sleep(1);
	[timer stopTimer];

## Requirements

## Installation

DZATimer is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod "DZATimer"
```

## Author

Davide Di Stefano, dzamirro@gmail.com

## License

DZATimer is available under the MIT license. See the LICENSE file for more info.
