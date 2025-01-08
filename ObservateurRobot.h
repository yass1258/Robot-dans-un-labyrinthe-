#ifndef OBSERVATEURROBOT_H_INCLUDED
#define OBSERVATEURROBOT_H_INCLUDED

class Robot;

class ObservateurRobot {
public:
    virtual ~ObservateurRobot() = default;

    // Méthode appelée lorsque le robot effectue une action
    virtual void notifier(const Robot& robot) = 0;
};

#endif // OBSERVATEURROBOT_H_INCLUDED
