class vehicle
{
private:
    double MaxSpeed;
    double Weight;

public:
    void Run() {}
    void Stop() {}
};
class bicycle : public vehicle
{
private:
    double Height;
};
class motorcar : public vehicle
{
private:
    int SeatNum;
};
class motorcycle : public bicycle, public motorcar
{
};
int main()
{
    motorcycle a;
    return 0;
}