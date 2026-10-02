(define get-operator (lambda (op-symbol env)
  (cond
    ((eq? op-symbol '+) +)
    ((eq? op-symbol '*) *)
    ((eq? op-symbol '-) -)
    ((eq? op-symbol '/) /)
    (else (display "cs305: ERROR\n\n") (repl env)))))


(define get-value (lambda (var env)
    (cond 
       ((null? env) (display "cs305: ERROR\n\n") (repl env))
       ((eq? var (caar env)) (cdar env))
       (else (if (null? (cdr env))
                 (begin
                   (display "cs305: ERROR\n\n")
                   (repl env))
                 (get-value var (cdr env)))))))


(define extend-env (lambda (var val old-env)
  (cons (cons var val) old-env)))

(define define-expr? (lambda (e)
  (and (list? e) (= (length e) 3) (eq? (car e) 'define) (symbol?(cadr e)))))

(define operator-expr? (lambda (e)
  (and (or (eq? (car e) '+) (eq? (car e) '-) (eq? (car e) '*) (eq? (car e) '/)) (> (length e) 2))))

(define if-expr? (lambda (e)
  (and (list? e) (= (length e) 4) (eq? (car e) 'if))))

(define cond-expr? (lambda (e)
	(and (list? e) (eq? (car e) 'cond) (> (length e) 2) (cond-expr-params-valid? (cdr e)))))

(define let-expr? (lambda (e)
  (and (list? e) (eq? (car e) 'let) (= (length e) 3) (let-expr-params-valid? (cadr e)))))

(define letstar-expr? (lambda (e)
  (and (list? e) (eq? (car e) 'let*) (= (length e) 3) (let-expr-params-valid? (cadr e)))))





(define let-expr-params-valid?
  (lambda (e)
    (cond
      ((not (list? e)) #f)
      ((null? e) #t)
      ((= (length (car e)) 2) (let-expr-params-valid? (cdr e)))
      (else #f))))


(define (cond-expr-params-valid? e)
  (cond
    ((null? e) #f)
    ((and (list? (car e)) (= (length (car e)) 2))
     (if (eq? (caar e) 'else)
         (null? (cdr e))
         (cond-expr-params-valid? (cdr e))))
    (else #f)))




(define s7 (lambda (e env)
  (cond
    ((number? e) e)
    ((symbol? e) (get-value e env))
    ((not (list? e)) (display "cs305: ERROR\n\n") (repl env))

    ((operator-expr? e) 
     (let ((operator (get-operator (car e) env))
           (operands (map s7 (cdr e) (make-list (length (cdr e)) env))))
       (apply operator operands)))
    
    ((if-expr? e)
     (if (= (s7 (cadr e) env) 0)
         (s7 (cadddr e) env)
         (s7 (caddr e) env)))
         
    ((cond-expr? e)
      (if (eq? (length e) 3) ;;when only one condition exists
        (if (eq? (s7 (caadr e) env) 0)
          (s7 (car (cdaddr e)) env)
          (s7 (cadadr e) env))
        (let (
           (if-cond (caadr e))
           (then (cadadr e))
           (else-part (cons 'cond (cddr e))))
        (let ((c (list 'if if-cond then else-part)))
          (s7 c env)))))


     ((letstar-expr? e)
      (cond
        ;;empty let* (turning it into let)
        ((null? (cadr e)) (s7 (list 'let '() (caddr e)) env))

        ;;one statement inside let* (turning it into let)
        ((eq? (length (cadr e)) 1) (s7 (list 'let (cadr e) (caddr e)) env))

        ;;multiple statements (regular let*)
        (else
          ;;calculating one by one
          (let* ((par (s7 (car (cdaadr e)) env))
            (newenv (cons (cons (caaadr e) par) env)))
            (s7 (list 'let* (cdadr e) (caddr e)) newenv)))))




    ((let-expr? e)
      ;;first extracting the symbols and expressions with map
      (let ((symbols (map car (cadr e)))
            (expressions (map cadr (cadr e))))
          ;;expressions are calculated
          (let ((vals (map (lambda (expr) (s7 expr env)) expressions)))
           	(let ((new-env (append (map cons symbols vals) env)))
            	(s7 (caddr e) new-env)))))






    (else (display "cs305: ERROR\n\n") (repl env)))))




(define repl (lambda (env)
   (let* (
           (dummy1 (display "cs305> "))
           (expr (read))
           (new-env (if (define-expr? expr) 
                        (extend-env (cadr expr) (s7 (caddr expr) env) env)
                        env
                    ))
           (val (if (define-expr? expr)
                    (cadr expr)
                    (s7 expr env)
                ))

           (dummy2 (display "cs305: "))
           (dummy3 (display val))
           (dummy4 (newline))
           (dummy5 (newline))
          )
          (repl new-env))))

(define cs305 (lambda () (repl '())))
