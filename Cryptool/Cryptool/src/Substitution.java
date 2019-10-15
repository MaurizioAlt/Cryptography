import java.util.Enumeration;
import java.util.Hashtable;


public class Substitution 
{
	public static void doSubstitution()
	{
		//gets text from ciphertext entry box
		String ciphertext = Cryptool.ngramsText.getText();
		ciphertext = ciphertext.toUpperCase();
			
		String subs[] = new String[26];
		
		//takes anything input by the user and puts the letter in the
		//corresponding index of the subs array
		for (int i = 0; i < 26; i++){
			subs[i] = Cryptool.guessBoxes[i].getText();
		}	
						
		String objPlaintext = "";

		//creates the string with the deciphered text
		for (int i = 0;  i < ciphertext.length(); i++)
		{
			//makes sure its substituting characters of the alphabet
			if (ciphertext.codePointAt(i) >= 65 && ciphertext.codePointAt(i) <= 90)
				objPlaintext += subs[ciphertext.codePointAt(i) - 65];
			else
				objPlaintext += ciphertext.charAt(i);
		}
		//sets the final text onto the screen for the user to view
		Cryptool.decipheredText.setText(objPlaintext);
	}
	
	/* Finds the frequencies of each letter within the cipher-text */
	public static void doFreq()
	{
		String text= Cryptool.ngramsText.getText();
		text = text.toUpperCase();
		double freq[] = new double[26];
		double total = 0;
		double percentage = 0;
		int temp = 0;
		
		
		for(int k=0;k<26;k++){
			freq[k] = 0;
		}
		
		//scans in each letter into an array
		for(int i=0;i<text.length();i++)
		{
			for(int j=0;j<26;j++)
			{
				if(Cryptool.alphabet[j].charAt(0) == (text.charAt(i)))
				{
					total++;
					freq[j]++;
				}
			}	
		}
		
		//calculates and rounds off the frequency based on the total number of letters
		for(int i=0;i<26;i++)
		{				
			percentage = ( 1000 * (freq[i]/total) );
			temp = (int)percentage;
			Cryptool.frequencies[i].setText("" + (((float)temp)/10) + "%"  );
		}
		
	}/* End of doFreq()*/
	
	/* Finds the repeated NGrams within the cipher-text */
	public static void doNGrams()
	{
		//takes in text from the nGramsText text area
		Cryptool.nGramsText.setText(" ");
		String text = Cryptool.ngramsText.getText();
		text = text.toUpperCase();
		
		String  fixedtext = "";
		
		//turns the input ciphertext into one single string with no spaces
		for (int i = 0; i < text.length(); i++){
			if (text.codePointAt(i) >= 65 && text.codePointAt(i) <= 90)
				fixedtext += text.charAt(i);
		}
		
		String nGrams = "";
		
		Hashtable numNGrams = new Hashtable();
		int count = 0;
		
		//for loops parse through each combination of strings within the fixed
		//text string to find out if they are repeated
		for (int i = 0; i < fixedtext.length() - 2; i++)
		{
			//makes sure that repeated letters are not considered repeated Ngrams
			for (int j = i+2; j < fixedtext.length() - 2; j++)
			{
				String str = "";

				for (int k = 0; k < fixedtext.length()-j; k++)
				{
					if (fixedtext.charAt(i+k) != fixedtext.charAt(j+k))
						break;
					str += fixedtext.charAt(i+k);
				}
				
				//the repeated Ngrams have to be of size 3 or greater
				if (str.length() >= 3)
				{
					if(numNGrams.containsKey(str))
					{
						count = (int) Integer.parseInt(numNGrams.get(str).toString());
						++count;
						numNGrams.put(new String(str),new Integer(count));
					}
					else
						numNGrams.put(new String(str),new Integer(2));
						
					/*if ((nGrams.matches(str+" ")) == false)
					{
						nGrams += str + " ";
						//sets the text on the screen for the user to view
						nGramsText.setText(nGrams);
					}*/
					
				}
			}
		}
		
		for(Enumeration e = numNGrams.keys(); e.hasMoreElements(); )
		{
			String key = (String) e.nextElement();
			nGrams += numNGrams.get(key) + " " + key + ", ";
		}
		
		// chop off last ', ' from string.
		nGrams = nGrams.substring(0, nGrams.length()-2);
		
		Cryptool.nGramsText.setText(nGrams);		
	}/*end of doNGrams()*/
}
