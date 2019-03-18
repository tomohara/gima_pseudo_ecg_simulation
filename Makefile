OBJS = ECG.o main.o APD.o concentrations.o buffers.o save.o stim.o currents.o dvdt.o fluxes.o gates.o LRd.o LRddata.o rates.o revpots.o update.o voltage.o

heads = LRd.h LRddata.h

CC = g++

CCFLAGS = -w 

exe: $(OBJS)
	$(CC) $(OBJS) -o exe 

main.o: main.cc $(heads)
	$(CC) -c $(CCFLAGS) main.cc
APD.o: APD.cc $(heads)
	$(CC) -c $(CCFLAGS) APD.cc
concentrations.o: concentrations.cc $(heads)
	$(CC) -c $(CCFLAGS) concentrations.cc
buffers.o: buffers.cc $(heads)
	$(CC) -c $(CCFLAGS) buffers.cc
save.o: save.cc $(heads)
	$(CC) -c $(CCFLAGS) save.cc
stim.o: stim.cc $(heads)
	$(CC) -c $(CCFLAGS) stim.cc
currents.o: currents.cc $(heads)
	$(CC) -c $(CCFLAGS) currents.cc
dvdt.o: dvdt.cc $(heads)
	$(CC) -c $(CCFLAGS) dvdt.cc
fluxes.o: fluxes.cc $(heads)
	$(CC) -c $(CCFLAGS) fluxes.cc
gates.o: gates.cc $(heads)
	$(CC) -c $(CCFLAGS) gates.cc
LRd.o: LRd.cc $(heads)
	$(CC) -c $(CCFLAGS) LRd.cc
LRddata.o: LRddata.cc $(heads)
	$(CC) -c $(CCFLAGS) LRddata.cc
rates.o: rates.cc $(heads)
	$(CC) -c $(CCFLAGS) rates.cc
revpots.o: revpots.cc $(heads)
	$(CC) -c $(CCFLAGS) revpots.cc
update.o: update.cc $(heads)
	$(CC) -c $(CCFLAGS) update.cc
voltage.o: voltage.cc $(heads)
	$(CC) -c $(CCFLAGS) voltage.cc
ECG.o: ECG.cc $(heads)
	$(CC) -c $(CCFLAGS) ECG.cc
