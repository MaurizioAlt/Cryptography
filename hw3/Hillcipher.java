/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hillcipher;

/**
 *
 * @author mauri
 */

import java.util.*;

public class Hillcipher
{

	final public static int mod = 26;
	public int[][] matrix = { {16, 04, 05, 22} , 
                                  {11, 14, 04, 24} , 
                                  {05, 07, 02, 25} , 
                                  {15, 22, 19, 19} };

        public Hillcipher(){
        }
        
	public String encrypt(String plain) 
        {
            String encrypted = "";
            for (int i=0; i<plain.length(); i+=4)
                encrypted = encrypted + encryptBlock(plain.substring(i,i+4));
            return encrypted;
	}

	private String encryptBlock(String block) 
        {
            char[] encryption = new char[4];
            for (int i=0; i<4; i++) 
            {
                int sum = 0;
                for (int j=0; j<4; j++)
                    sum += (matrix[i][j]*(block.charAt(j)-'a'));
                encryption[i] = (char)('a'+(sum%mod));
            }
            return new String(encryption);
	}

	public static void main(String[] args) 
        {
            Hillcipher encrypter = new Hillcipher();
            System.out.println(encrypter.encrypt("jackandjillwentdownahilltofetchapailofwaterx"));
	}
}
