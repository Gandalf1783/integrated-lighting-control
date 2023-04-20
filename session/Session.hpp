#ifndef SESSION_HPP
#define SESSION_HPP

class Session {

    public:
        Session();

    private:
        unsigned int sessionID;
        char* sessionName;
        unsigned int deviceIDMaster;
        
};

#endif