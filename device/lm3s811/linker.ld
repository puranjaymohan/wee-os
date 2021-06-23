ENTRY(Reset_Handler)
_estack = 0x20001FFF;

MEMORY
{
	FLASH (rx) : ORIGIN = 0x0 , LENGTH = 64K
	RAM (rwx) : ORIGIN = 0x20000000 , LENGTH = 8K
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
