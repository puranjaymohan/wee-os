ENTRY(Reset_Handler)
_estack = 0x20000000;

MEMORY
{
	FLASH (rx) : ORIGIN = 0x0 , LENGTH = 1M
	RAM (rwx) : ORIGIN = 0x1fff0000, LENGTH = 64K
}

SECTIONS
{
	.text :
	{
		. = ALIGN(4);
		KEEP(*(.vectors))
		*(.text)
		*(.text*)
		*(.rodata)
		*(.rodata*)
		. = ALIGN(4);
	} > FLASH

	.data :
	{
		. = ALIGN(4);
		_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		_edata = .;
	} > RAM AT > FLASH

	_ldata = LOADADDR(.data);

	.bss :
	{
		_sbss = .;
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		_ebss = .;
	} > RAM

}
