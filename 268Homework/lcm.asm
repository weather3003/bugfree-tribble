;  int LCM (int a, int b)
;  Daryl Bagley
;	Takes two positive integers and returns the least common multiple

	.386
	.model flat,c
	.data

	.code

;******** Defintion of LCM ****************************
LCM	proc	uses ebx ecx edx, a:dword, b:dword				; int LCM (int a, int b) {

															; int t (Will use EDX to store the variable, t)

	mov ebx, a												; int x = a (EBX will be x)
	mov ecx, b												; int y = b (ECX will be y)

	mov		eax, ebx										; t = x % y
	cdq
	idiv	ecx
  ; t is already edx so no worries

while1:														;   while (t > 0) {
	cmp	edx, 0
	jg	while1_begin
	jmp	while1_end

while1_begin:
	mov		ebx, ecx										;	   x = y;
	mov		ecx, edx										;	   y = t;

	mov		eax, ebx										;	   t = x % y;
	cdq
	idiv	ecx

	jmp	while1

while1_end:													;	}
	mov		eax, a											; answer (EAX) = b * (a / y)
	cdq
	idiv	ecx
	imul	b
	ret

LCM	endp													; }
;******************************************************

	end