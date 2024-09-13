



.data

MB_OK    EQU 0
;EXTERN MessageBoxA@16:NEAR

.code

;//---------------------------------test proc 
_test_pidr proc

;PUSH     MB_OK
;call     MessageBoxA@16

mov rax,rcx
ret

_test_pidr endp

end
;//---------------------------------