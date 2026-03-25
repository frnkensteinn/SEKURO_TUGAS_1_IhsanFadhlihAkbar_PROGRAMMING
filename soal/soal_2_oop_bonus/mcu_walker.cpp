#include "mcu_walker.hpp"
using namespace std;

mcu_walker::mcu_walker(float cpu_speed, int memory, string os, string nama, int volt, int motor_speed, int rotation)
    : MCU(cpu_speed, memory, os, nama, volt) {
    this->motor_speed = motor_speed;
    this->rotation = rotation;
    cout << "[KONSTRUKTOR WALKER] : Sistem gerak " << name << " telah diinisialisasi." << endl;
}

void mcu_walker::rotate(int new_rotation) {
    cout << "[WALKER] : " << name << " berputar ke arah " << new_rotation << " derajat." << endl;
    rotation = new_rotation;
}

void mcu_walker::increase_speed(int speed) {
    motor_speed += speed;
    cout << "[WALKER] : Kecepatan motor " << name << " naik menjadi " << motor_speed << " RPM." << endl;
}

void mcu_walker::showSpek() {
    cout << "[SPEK MCU_WALKER] : " << name << endl;
    cout << "- CPU      : " << cpu_speed << " GHz" << endl;
    cout << "- RAM      : " << memory << " MB" << endl;
    cout << "- OS       : " << os << endl;
    cout << "- Volt     : " << volt << " V" << endl;
    cout << "- Speed    : " << motor_speed << " RPM" << endl;
    cout << "- Rotation : " << rotation << " Deg" << endl;
}

void mcu_walker::nambah_volt(int penambahan_voltase) {
    volt += penambahan_voltase;
}

void mcu_walker::ganti_os(string new_os) {
    cout << "[WALKER UPDATE] : " << name << " migrasi OS ke " << new_os << endl;
    os = new_os;
}

mcu_walker::~mcu_walker() {
    cout << "[DESTRUKTOR WALKER] : Komponen walker " << name << " telah dimatikan." << endl;
}