HANOI    SUBENTRY BASES = (3)
         WTOR  'Ingrese la cantidad de discos',CINPUT,,WAITECB
         WAIT  ECB=WAITECB
         PACK  PINPUT(8),CINPUT(2)
         CVB   1,PINPUT
         ST    1,CNTDISC
         BAL   15,INIT

         MVC   TIZQ(132),=33F'0'

         SUBEXIT

INIT     MVC   TIZQ(132),=33F'0'



WAITECB  DC    F'0'
CINPUT   DS    CL2
PINPUT   DS    PL8
CNTDISC  DS    F

TIZQ     DS    0CL44
ICANT    DS    F
IVECT    DS    10F

TCENTRO  DS    0CL44
CCANT    DS    F
CVECT    DS    10F

TDER     DS    0CL44
DCANT    DS    F
DVECT    DS    10F
         END
