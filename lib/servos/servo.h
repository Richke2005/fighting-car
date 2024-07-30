class Servo
{
public:
    Servo(int *arg, bool data);

    Servo(int *arg, int *position);

private:
    int *arg;
    bool data;
    int *position;
};