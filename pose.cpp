#include "pose.h"
#include <cmath>
#include <iostream>
#include <grid_map_core/TypeDefs.hpp>

using namespace std;

Pose::Pose(float aX, float aY, float orientation, int range, double FOV) {
  Pose::aX = aX;
  Pose::aY = aY;
  Pose::orientation = orientation;
  Pose::range = range;
  Pose::FOV = FOV;
}

Pose::Pose() {}

Pose::~Pose() {}

double Pose::getDistance(Pose &pose) {
  return std::sqrt((aX - pose.getX()) * (aX - pose.getX()) +
                   (aY - pose.getY()) * (aY - pose.getY()));
}

float Pose::getX() { return aX; }

float Pose::getY() { return aY; }

float Pose::getOrientation() { return orientation; }

int Pose::getRange() { return range; }

double Pose::getFOV() { return FOV; }

bool Pose::isEqual(Pose &p) {
  if (aX == p.getX() & aY == p.getY() & orientation == p.getOrientation() &
      FOV == p.getFOV() & range == p.getRange()) {
    return true;
  } else
    return false;
}

int Pose::getInformationGain() { return informationGain; }

void Pose::setInformationGain(int value) { Pose::informationGain = value; }

bool Pose::operator==(const Pose &p) {
  Pose p2 = p;
  // std::cout <<aX<<" "<<aY<<" "<<orientation<<" "<<FOV<<" "<<range<<std::endl;
  // std::cout<<p2.getX()<<" "<<p2.getY()<<" "<<p2.getOrientation()<<"
  // "<<p2.getFOV()<<" "<<p2.getRange()<<std::endl;
  // std::cout<< "compare " << (aX == p2.getX()) <<" "<< (aY == p2.getY()) <<"
  // "<< (orientation == p2.getOrientation()) <<" "<< (FOV == p2.getFOV()) <<"
  // "<< (range == p2.getRange() )<<std::endl;
  return (aX == p2.getX()) && (aY == p2.getY()) &&
         (orientation == p2.getOrientation()) &&
         ((int)FOV == (int)(p2.getFOV())) && (range == p2.getRange());
}

void Pose::setScanAngles(std::pair<double, double> angles) {
  // cout << angles.first << ":"<<angles.second << endl;
  scanAngles = angles;
}

void Pose::setOrientation(float orientation) {
  this->orientation = orientation;
}

std::pair<double, double> Pose::getScanAngles() { return scanAngles; }

void Pose::updateFromGridMapPosition(grid_map::Position p, float orientation, int range, double FOV) {
  this->aX = p(0);
  this->aY = p(1);
  this->orientation = orientation;
  this->range = range;
  this->FOV = FOV;
}
