(define main-procedure
  (lambda (tripleList)
  (if (or (null? tripleList) (not (list? tripleList)))
    (error "ERROR305: the input should be a list full of triples")
    (if (check-triple? tripleList)
      (sort-area (filter-pythagorean (filter-triangle
      (sort-all-triples tripleList))))
      (error "ERROR305: the input should be a list full of triples")))))


(define check-triple?
  (lambda (tripleList)
    (if (null? tripleList)
        #t
        (if (and (= (length (car tripleList)) 3)
                 (number? (car (car tripleList)))
                 (number? (cadr (car tripleList)))
                 (number? (caddr (car tripleList))))
            (check-triple? (cdr tripleList))
            #f))))




(define check-length?
    (lambda (inTriple count)
        (if (= (length inTriple) count) #t #f)))



(define check-sides?
  (lambda (tripleList)
    (if (and (and (number? (car tripleList)) (> (car tripleList) 0))
             (and (number? (cadr tripleList)) (> (cadr tripleList) 0))
             (and (number? (caddr tripleList)) (> (caddr tripleList) 0)))
        #t
        #f)))



(define sort-all-triples
  (lambda (tripleList)
    (if (null? tripleList)
        '()
        (cons (sort-triple (car tripleList))
              (sort-all-triples (cdr tripleList)))))) 



(define sort-triple
  (lambda(inTriple)
    (sort inTriple <)))



(define triangle?
  (lambda (triple)
    (let ((x (car triple))
          (y (cadr triple))
          (z (caddr triple)))
          (if (and (> (+ x y) z) (> (+ y z) x) (> (+ z x) y))
            #t
            #f
           ))))



(define filter-triangle
  (lambda (tripleList)
    (if (null? tripleList)
        '()
        (if (triangle? (car tripleList))
            (cons (car tripleList) (filter-triangle (cdr tripleList)))
            (filter-triangle (cdr tripleList))))))



(define pythagorean-triangle?
  (lambda (triple)
    (let ((x (car triple))
          (y (cadr triple))
          (z (caddr triple)))
          (if (= (+ (* x x) (* y y)) (* z z))
            #t
            #f
           ))))



(define filter-pythagorean
  (lambda (tripleList)
    (if (null? tripleList)
        '()
        (if (pythagorean-triangle? (car tripleList))
            (cons (car tripleList) (filter-pythagorean (cdr tripleList)))
            (filter-pythagorean (cdr tripleList))))))



(define get-area
  (lambda (triple)
    (let ((a (car triple))
          (b (cadr triple))
          (c (caddr triple)))
          (* (* a b) 1/2))))



(define sort-area
  (lambda (tripleList)
    (sort tripleList (lambda (firstTriple secondTriple) (< (get-area firstTriple) (get-area secondTriple))))))
