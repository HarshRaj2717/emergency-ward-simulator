#include <cassert>
#include <stdexcept>
#include <queue>
#include <vector>

class Doctor;
class Patient;
class EmergencyWard;
class EmergencyWardManager;

enum PatientType
{
    P0,
    P1
};

class Doctor
{
    friend EmergencyWard;
    bool isFree_;
    int curOperationEndTime_;

    Doctor() : isFree_{true}, curOperationEndTime_{-1} {}

public:
    bool getIsFree() const { return isFree_; }
    void setIsFree(const bool isFree) { isFree_ = isFree; }
};

class Patient
{
    friend EmergencyWardManager;
    int waitedTime_;
    int operationTime_;
    PatientType patientType_;

    Patient(const PatientType patientType, const int operationTime) : waitedTime_{0}, patientType_{patientType}, operationTime_{operationTime} {}
};

class EmergencyWard
{
    friend EmergencyWardManager;
    const int totalNumberOfDoctors;
    int curTime;
    std::queue<Doctor *> freeDoctors;
    std::priority_queue<Doctor *> preemptableBusyDoctors;
    std::priority_queue<Doctor *> nonPreemptableBusyDoctors;
    std::deque<Patient *> p0Patients;
    std::deque<Patient *> p1Patients;

public:
    EmergencyWard(const int totalNumberOfDoctors) : totalNumberOfDoctors{totalNumberOfDoctors}, curTime{0}
    {
        for (int _ = 0; _ < totalNumberOfDoctors; _++)
        {
            freeDoctors.push(new Doctor());
        }
    }

    ~EmergencyWard() noexcept
    {
    }
};

class EmergencyWardManager
{
    EmergencyWard *emergencyWardRef;

public:
    EmergencyWardManager(EmergencyWard *emergencyWardRef) : emergencyWardRef{emergencyWardRef} {}

    /**
     * @todo:
     * - simulate everything till the current arrival time
     * - add the current patient to the queue
     * - move the current patient to a doctor if possible
     */
    void addPatient(const PatientType patientType, const int operationTime, const int arrivalTime) const
    {
        Patient *curPatient = new Patient(patientType, operationTime);
        /**
         * @todo:
         * - simulate everything till the current arrival time
         * - add the current patient to the queue
         * - move the current patient to a doctor if possible
         */
    }

    void printCurrentSystemState(int curTime)
    {
        if (curTime < emergencyWardRef->curTime)
        {
            throw std::invalid_argument("inout time less than the current time, can't print past state now!");
        }
        /**
         * @todo print the system state here...
         */
    }
};

int main()
{

    return 0;
}