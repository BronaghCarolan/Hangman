#include <qapplication.h>
#include "visHang.h"

main(int argc, char *argv[]){
  QApplication a(argc, argv);
  visHang hang;
  hang.show();
  a.exec();
}
