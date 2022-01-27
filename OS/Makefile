ARMGNU ?= aarch64-linux-gnu

COPS = -Wall -nostdlib -nostartfiles -ffreestanding -Iinclude -mgeneral-regs-only -g -O0
ASMOPS = -Iinclude  -g

all: clean kernel8.img

start.o: kernel/start.S
	$(ARMGNU)-gcc $(COPS) -MMD -c kernel/start.S -o start.o


entry.o: kernel/entry.S
	$(ARMGNU)-gcc $(COPS) -MMD -c kernel/entry.S -o entry.o


irq.o: modules/interrupt/irq.S
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/interrupt/irq.S -o irq.o

utils.o: utils.S
	$(ARMGNU)-gcc $(COPS) -MMD -c utils.S -o utils.o

tim.o: modules/timer/timer.S
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/timer/timer.S -o tim.o

mm.o: mm.S
	$(ARMGNU)-gcc $(COPS) -MMD -c mm.S -o mm.o


scheduler.o: kernel/scheduler.c
	$(ARMGNU)-gcc $(COPS) -MMD -c kernel/scheduler.c -o scheduler.o


gpio.o: modules/gpio/gpio.c
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/gpio/gpio.c -o gpio.o


led.o: modules/led/led.c
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/led/led.c -o led.o

mini_uart.o: modules/mini_uart/mini_uart.c
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/mini_uart/mini_uart.c -o mini_uart.o

timer.o: modules/timer/timer.c
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/timer/timer.c -o timer.o


interrupt.o: modules/interrupt/interrupt.c
	$(ARMGNU)-gcc $(COPS) -MMD -c modules/interrupt/interrupt.c -o interrupt.o

printf.o: printf.c
	$(ARMGNU)-gcc $(COPS) -MMD -c printf.c -o printf.o

app.o: app.c
	$(ARMGNU)-gcc $(COPS) -MMD -c app.c -o app.o


kernel8.img: start.o utils.o mm.o entry.o irq.o tim.o gpio.o led.o mini_uart.o app.o interrupt.o printf.o timer.o scheduler.o 
	$(ARMGNU)-ld -nostdlib -nostartfiles start.o utils.o mm.o entry.o irq.o tim.o gpio.o led.o mini_uart.o app.o interrupt.o printf.o timer.o scheduler.o -T linker.ld -o kernel8.elf
	$(ARMGNU)-objcopy -O binary kernel8.elf kernel8.img

clean:
	/bin/rm kernel8.elf *.o *.img > /dev/null 2> /dev/null || true

