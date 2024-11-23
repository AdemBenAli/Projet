#ifndef MAILER_H
#define MAILER_H

#include <maintenance.h>
class mailer
{
public:
    mailer();
    static int sendEmail(Maintenance* m);
};

#endif // MAILER_H
