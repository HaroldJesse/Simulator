#include "Craft.hpp"

// Craft time

int Craft::CraftTime = 0; // time in seconds

// Initialize static varaiables
bool  Craft::ThrusterSync = false;
QVector3D Craft::Attitude(0,0,0);
QVector3D Craft::Velocity(0,0,0);
QQuaternion Craft::RotationQuat (1,0,0,0); //Identity Quaternion
QVector3D Craft::CartPosition (0,0,0);
double Craft::FuelTanks(2.0);
double Craft::OxidizerTanks(2);
double Craft::ThrusterFuel (418.67);
double Craft::ThrusterOxidizer (664.06);
double Craft::VernierThrust (10.88); //Kilograms
double Craft::PrimaryThrust (394.63); //Kilograms


// TRANSLATION
QVector3D Craft::ShipTranslation (0,0,0);

//Forward/Reverse
double Craft::FwdRevThrottle (0);
bool   Craft::FwdRevThrusterOn (false);
double Craft::FwdRevDirection (0);
double Craft::FwdRevThrust(0);

//Port/Starboard
double Craft::PrtSrbThrottle (0);
bool   Craft::PrtSrbThrusterOn (false);
double Craft::PrtSrbDirection (0);
double Craft::PrtSrbThrust(0);

//Up/Down
double Craft::UpDwnThrottle (0);
bool   Craft::UpDwnThrusterOn (false);
double Craft::UpDwnDirection (0);
double Craft::UpDwnThrust(0);

// ROTATION

//Pitch
double Craft::PitchThrottle (0);
bool   Craft::PitchThrusterOn = false;
double Craft::PitchDirection (0);
double Craft::PitchThrust (0);
double Craft::PitchAngle (0);

//Yaw
double Craft::YawThrottle (0);
bool   Craft::YawThrusterOn = false;
int    Craft::YawDirection (0);
double Craft::YawThrust (0);
int    Craft::YawAngle (0);

//Roll
double Craft::RollThrottle (0);
bool   Craft::RollThrusterOn = false;
int    Craft::RollDirection (0);
double Craft::RollThrust (0);
int    Craft::RollAngle (0);

QVector3D Craft::Heading (0,0,0);
float     Craft::Direction (0);
float     Craft::Mark (0);
float     Craft::Distance(0);

Craft::Craft()
{

}
