(define get-operator (lambda (op-symbol)
  (cond
    ((eq? op-symbol '+) +)
    ((eq? op-symbol '*) *)
    ((eq? op-symbol '-) -)
    ((eq? op-symbol '/) /)
    (else (error "s5: unknown operator --> " op-symbol)))))

(define s5 (lambda (e)
   (cond
      ( (number? e) e)
      ( (not (list? e)) (error "s5: cannot evaluate --> " e))
      ( (not (> (length e) 1)) (error "s5: cannot evaluate --> " e))
      ( else 
         (let (
                (operator (get-operator (car e)))
                (operands (map s5 (cdr e)))
              )
              (apply operator operands))))))
