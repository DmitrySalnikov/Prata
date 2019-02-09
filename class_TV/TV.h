#pragma once

#include <iostream>

class Remote;
class TV {
public:
    friend class Remote;
    enum {Off = 0, On = 1};
    enum {MinVal = 0, MaxVal = 20};
    enum {Antenna = 0, Cable = 1};
    enum {Tv = 0, VCR = 1};
    TV(int state = Off, int max_chan = 100) : state_(state), volume_(5), max_channel_(max_chan), channel_(1), mode_(Cable), input_(Tv) {}
    void onoff() { state_ = (state_ + 1) % 2; }
    bool ison() const { return state_ == On; }
    bool volup() { if (volume_ < MaxVal) { volume_++; return true; } else return false; }
    bool voldown() { if (volume_ > MinVal) { volume_--; return true; } return false; }
    void chanup() { channel_ < max_channel_ ? channel_++ : channel_ = 1; }
    void chandown() { channel_ > 1 ? channel_-- : channel_ = max_channel_; }
    void set_mode() { mode_ = (mode_ + 1) % 2; }
    void set_input() { input_ = (input_ + 1) % 2; }
    void settings() const { 
        using std::cout;
        using std::endl;
        cout << "TV is " << (state_ == On ? "on" : "off") << endl;
        if (state_ == On) {
            cout << "Volume " << volume_ << endl;
            cout << "Channel " << channel_ << endl;
            cout << "Condition " << (mode_ == Antenna ? "antenna" : "cable") << endl;
            cout << "Input " << (input_ == Tv ? "TV" : "VCR") << endl;
        }
    }
    void set_condition(Remote & remote);

private:
    int state_;
    int volume_;
    int channel_;
    int max_channel_;
    int mode_;
    int input_;
};

class Remote {
public:
    friend class TV;
    enum {Normal = 0, Interactive = 1};
    Remote(int mode = TV::Tv, int condition = Normal) : mode_(mode), condition_(condition) {}
    bool volup(TV & tv) { return tv.volup(); }
    bool voldown(TV & tv) { return tv.voldown(); }
    void onoff(TV & tv) { tv.onoff(); }
    void chanup(TV & tv) { tv.chanup(); }
    void chandown(TV & tv) { tv.chandown(); }
    bool set_channel(TV & tv, int channel) { if (channel <= tv.max_channel_) { tv.channel_ = channel; return true; } return false; }
    void set_mode(TV & tv) { tv.set_mode(); }
    void set_input(TV & tv) { tv.set_input(); }
    void settings() { 
        std::cout << "Mode " << (mode_ == TV::Tv ? "Normal" : "Interactive") << std::endl; 
        std::cout << "Condition " << (condition_ == Normal ? "Normal" : "Interactive") << std::endl; 
    }

private:
    int mode_;
    int condition_;
};
    
inline void TV::set_condition(Remote & remote) { remote.condition_ = (remote.condition_ + 1) % 2; }
