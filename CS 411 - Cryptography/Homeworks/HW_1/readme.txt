QUESTION 1:

First I saved the corresponding letter indexes from the ciphertext to a list and also every possible letter shifts to a another list.
Then I tried every key possibilities using my letter_list[ciphertext index - key] then added them to the another string list.

In the list meaningful words are: BUNNY, SLEEP
and their corresponding keys are: 12, 21




QUESTION 2:


In the program first we find the most frequent letters in the cipher text. (S and Z)
We try to find every possible key with the given hint.
T either encrypted as S or Z

First we find the values of alpha with the gcd funtion then using the hint we pair two letters (T,S) and (T,Z)
Using the formula we find possible beta values using our alpha values. 
We append every possible key to the list and then decrypt them with the given Affine_Dec function

When we check the possible decryptions we can see the correct decryption and its corresponding key

Plain Text is: "THOUGH THIS BE MADNESS, YET THERE IS METHOD IN IT."
Correct Key is: [23, 4]. 
Alpha: 23 Beta: 4 Gamma: 17 Theta: 10




QUESTION 3:

Modulus is 784 because in the new biagram alphabet there are 784 different combinations with the given letters.
Length of our new alphabetis the modulus.
While using the phi() function have found the amount of alpha values and since beta can take every value.
When we multiply alpha amount with beta amount we find that Key Space is 263424.




QUESTION 4:

Yes, affine cipher defined in question 3 is Secure against the frequency analysis. (different modulus than english alphabet)




QUESTION 5:

I'm gonna use my newly created dictionary that I created in Question 3.
Then reverse it so that we can use it for our decryption.

We did found the modulos in Question 3 so while using that we calculate the possible alpha values
And then with the given hints and affine formula we find the corresponding beta values with our possible alpha values.
And then we have possible keys in our list.

After that we need to customize the given "Affine_Dec" function so that it can work with our new dictionary and biagram alphabet.
And then we try our every possible keys to find a meaninful sentence. 
After checking every key we have found our key and plain text which is:

Plain Text: "I HAVE COME TO BELIEVE THAT THE WHOLE WORLD IS AN ENIGMA."
Key: (185, 524),    alpha = 185 and beta = 524




QUESTION 6:

1. First we create a message to be encrypted and then turn it to bits.
2. We generate a random key with the same length as the plain text bits.
3. and then we put these bit representations to xor function to generate the cipher bits.
4. We check the frequency of the zeros and one and find that with every run they are very close to 0.5 so we can say that probabilty the letter alpha is 1/29 and it is perfect security.




QUESTION 7:

First we need to find the key length and by shifting the cipher text we can see where the graph spikes.
Until shift 8, coincedences stay between 20 and 30 but when shifting comes to 6 it becomes 65.

So we have found that Key Length is 6.

After creating the key length we need to create sub_ciphers according to our key length.
I created a new dictionary which contains the letter frequencies of the english alphabet named as eng_letter_frequency.
Starting from the shift 0 we check for every shift and compare which is closest to the eng_letter_frequency.

3 functions are used:
Shift function shifts the letters of the given text with the given number using modulos 26
calculate_frequency function counts the letters in text and and divides it with the length of the text and adds the value to the dictionary.
compare function just compares two dictionaries and adds their difference key by key then returns it.

With these functions we have found our key with the lowest deviancy from the english letter frequencies:
Key is: [24, 13, 0, 2, 8, 16]

Only thing left is Decryption
We iterate over every character of the cipher text
If we come across something other than letter we directly add it to our plain text.
But if it is a letter we shift it according to our key and change our index in the key.
We also control that our position (index) in the key does not exceed 5.


Plain Text is: HE WALKED AT THE OTHER’S HEELS WITH A SWING TO HIS SHOULDERS, AND HIS LEGS SPREAD UNWITTINGLY,
 AS IF THE LEVEL FLOORS WERE TILTING UP AND SINKING DOWN TO THE HEAVE AND LUNGE OF THE SEA. THE WIDE ROOMS SEEMED
  TOO NARROW FOR HIS ROLLING GAIT, AND TO HIMSELF HE WAS IN TERROR LEST HIS BROAD SHOULDERS SHOULD COLLIDE WITH THE
   DOORWAYS OR SWEEP THE BRIC-A-BRAC FROM THE LOW MANTEL. HE RECOILED FROM SIDE TO SIDE BETWEEN THE VARIOUS OBJECTS
    AND MULTIPLIED THE HAZARDS THAT IN REALITY LODGED ONLY IN HIS MIND. BETWEEN A GRAND PIANO AND A CENTRE-TABLE PILED
     HIGH WITH BOOKS WAS SPACE FOR A HALF A DOZEN TO WALK ABREAST, YET HE ESSAYED IT WITH TREPIDATION. HIS HEAVY ARMS HUNG
      LOOSELY AT HIS SIDES. HE DID NOT KNOW WHAT TO DO WITH THOSE ARMS AND HANDS, AND WHEN, TO HIS EXCITED VISION, ONE ARM SEEMED
       LIABLE TO BRUSH AGAINST THE BOOKS ON THE TABLE, HE LURCHED AWAY LIKE A FRIGHTENED HORSE, BARELY MISSING THE PIANO STOOL.
        HE WATCHED THE EASY WALK OF THE OTHER IN FRONT OF HIM, AND FOR THE FIRST TIME REALIZED THAT HIS WALK WAS DIFFERENT FROM THAT OF
         OTHER MEN. HE EXPERIENCED A MOMENTARY PANG OF SHAME THAT HE SHOULD WALK SO UNCOUTHLY. THE SWEAT BURST THROUGH THE SKIN OF HIS FOREHEAD
          IN TINY BEADS, AND HE PAUSED AND MOPPED HIS BRONZED FACE WITH HIS HANDKERCHIEF.

