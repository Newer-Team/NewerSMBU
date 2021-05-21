objs\waveplatform.o: src/waveplatform.cpp ../include/game.h \
 ../include/actorbases.h ../include/nw4f.h ../include/cafe.h \
 ../include/types.h ../include/common.h ../include/gx2.h ../include/physics.h \
 ../include/actors.h ../include/states.h ../include/enums.h \
 ../include/effectclasses.h ../include/effects.h ../include/graphics.h \
 ../include/players.h ../include/sounds.h ../include/blockcoin.h \
 ../include/movement.h ../include/imports.h ../include/ghs.h \
 ../include/miis.h ../include/zlib.h src/neweru.h

:cmdList=cxppc  -c  -MD -I../include -bsp generic -cpu=espresso -object_dir=objs -Ogeneral --g++ --no_rtti -DREGION_Kinnay -DCODE_ADDR=0xf800000 -DDATA_ADDR=0x10400000 -filetype.cc src/waveplatform.cpp -o objs\waveplatform.o ; 
:cmdHash=0x38eb0133
