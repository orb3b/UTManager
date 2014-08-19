#include "CommandLine.h"


CommandLine::CommandLine()
{
}


// Usage
class RosterCommandLine : public CommandLine
{
    RosterCommandLine();
    virtual ~RosterCommandLine();

    int language() {
        if (m_languageSwitch.value().toString() == "ru")
            return Russian;
        return English;
    }

    bool compatibilityMode() {
        return m_compatibilitySwitch.isEnabled();
    }

};

enum Language
{
    Russian,
    English
};

int main(int argc, char *argv[])
{
    RosterCommandLine cmd(argc, argv);

    switch(cmd.language()) {
    case Russian:
        addTransaltorRussian();
        break;
    case English:
        break;
    }
}
