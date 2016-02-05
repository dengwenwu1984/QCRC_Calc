#ifndef CRC_CALC_FOR_HEX_H
#define CRC_CALC_FOR_HEX_H


#include <QObject>

#include "hextobytes.h"
#include "qucrc_t.h"
#include "qexecthread.h"





class CRC_Calc_for_Hex : public QObject
{
    Q_OBJECT

    public:
        explicit CRC_Calc_for_Hex();
        ~CRC_Calc_for_Hex();


        size_t size() { return hex_to_bytes.bytes.size(); }
        void set_ucrc(const QuCRC_t *crc) { ucrc = crc; }



    signals:
        void calculated(uint64_t value);
        void error(const QString & err);

        //signals for inner use
        void run_calculate(const QString & data);



    public slots:
        void calculate(const QString & data);
        void set_revers_chunk(bool value) { hex_to_bytes.revers_chunk = value; }
        void set_revers_data(bool value)  { hex_to_bytes.revers_data  = value; }



    protected slots:
        void _calculate(const QString & data);



    private:
        HexToBytes      hex_to_bytes;
        const QuCRC_t  *ucrc;
        QExecThread     thread;
};





#endif // CRC_CALC_FOR_HEX_H