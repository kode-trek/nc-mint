/*************************************************************************
**                          mail.class
**
**  Simple STMP Mail Server Class. Instanciate the object with the STMP server 
**  and port . Port is typically 25
**  Server is your server. ( Example -> mail.texas.net )
    
    mail mymail = new mail( "mail.texas.net",25 )

**
**  Public Methods

    MesgTo      (String   s )       - Single Recipient
    MesgTo      (String[] s )       - Multiple Recipients
    MesgFrom    (String   s )       - Your mail account
    MesgSubject (String   s )       - Subject of the Email
    MesgBody    (String   s )       - actual email message to send
    Attachment  (String   s )       - string name of Attachment ( assumes no attachement)
    SetMIMEType (String   s )       - type of Attachment. Program will "guess" if
                                      not supplied.
    MesgSend    ()                  - send the mail after above parameters set
    
**
**
**  Class will transmit a mail message with or without an Attachment. 
**
**  Common MIME types are included. Add missing types as needed. 
**  tested MIMES are .Txt, .GIF, .JPEG, .EXE, .ZIP 
**  User can set the MIME type with SetMIMEType() method. If not set the file 
**  extension is tested to determine the probable type. 
**
**  To send to multiple users, pass a String[] to MesgTo() method.
**
**  MesgSend() returns FALSE if port could not be opened.

****************************************************************************/
import java.net.*;
import java.io.*;
import java.util.*;

public class mail {
    
           String[]     To; 
           String       From;
           String       Subject;
           String       Server;
           String       Message;
           String       MimeType;
           String       AttachedFile;
           int          Port ;
           BufferedReader in;
           BufferedWriter out;
           boolean Attachment;
           static String BaseTable[] = { 
                "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P",
                "Q","R","S","T","U","V","W","X","Y","Z","a","b","c","d","e","f",
                "g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v",
                "w","x","y","z","0","1","2","3","4","5","6","7","8","9","+","/"
            };

           
    public mail(String Server , int Port) {
    this.Server = Server;
    this.Port = Port;
    Attachment = false;
    MimeType = null;
    }    

        
    // Single recipient 
    public  void  MesgTo (String s) {
       To = new String[1];
       To[0] = s;
       return;
    }
    
    // Multiple recipient's
    public  void MesgTo (String[] s) {
       To = new String[s.length];
       for (int i = 0 ; i < s.length;i++) 
            To[i] = s[i];
    }

    // Your email address
    public  void MesgFrom (String s) {
       From = new String(s);
    }
    
    // Subject of the email
    public  void MesgSubject (String s) {
       Subject = new String(s);
    }
    
    // actual mail text
    public  void MesgBody (String s) {
       Message = new String(s);
    }
    
    // attachment, if there.
    public  void Attachment (String s) {
     Attachment = true;
     AttachedFile = s;
     if ( MimeType == null)
        MimeType = GuessMIMEType(s);
    }

    // type of attachment. If not entered , program will "guess" the type based on extension
    public  void    SetMIMEType( String s) {
        MimeType = s;
    }    
    
    
    // now send it
    public  boolean MesgSend () {
      return sendMail();
       
    }
    
     
    /***********************************************************************************
    **      the remaining methods are private to the class to manulate the requests
    **      and transmit the mail.
    ************************************************************************************/
        
    private boolean sendMail () {    
    try {
        Socket s = new Socket (Server,Port);
        in = new BufferedReader(new InputStreamReader(s.getInputStream(), "8859_1"));
        out =  new BufferedWriter(new OutputStreamWriter(s.getOutputStream(), "8859_1"));
        send(in,out,"HELO SomeDomain");
        send(in,out,"RSET");
        send(in,out,"MAIL FROM:" + From);
        int i = 0;
        for (i = 0; i < To.length; i++) 
            send(in,out,"RCPT TO:" + To[i]);
        
        send(in,out,"DATA");
        send(out,"SUBJECT:" + Subject);
        
        out.write("TO:");
        
        for (i = 0; i < To.length-1; i++) 
            out.write(To[i]+",");
        send(out,To[i]);
        
        if (Attachment) {
            // NOTE : StartOfNextPart is just the boundary name I picked. Arbitrary
            send(out,"Content-Type: multipart/mixed;\n boundary=\"StartOfNextPart\"");
            send(out,"MIME-Version: 1.0");     
            send(out,"\n--StartOfNextPart");
            send(out,"Content-Type: text/plain; charset=\"us-ascii\"");
            send(out,"Content-Transfer-Encoding: 7 bit\n");
        }
        send(out,Message);  // send the mail text body first. If there is no Attachment
                            // above messages not needed.
        if ( Attachment) {
            send(out,"\n\n--StartOfNextPart");
            sendAttachment(MimeType);
        }
        send(in,out,".");
        send(in,out,"QUIT");
        s.close();
        return true;
        }catch (IOException e){ return false;} 
    }

    
    
    // used when a returned response is expected from the mail server
    private  void    send (BufferedReader in, BufferedWriter out, String s) {
     try{
        out.write(s + "\n");
        out.flush();
        in.readLine();
     }catch (IOException e){}
     
    }
    // used when NO response is expected from the mail server
    private  void    send (BufferedWriter out, String s) {
     try{
        out.write(s + "\n");
     }catch (IOException e){}
    }
    
    // add additional types as required            
    private  String GuessMIMEType(String file){   
        if ( file.toLowerCase().endsWith(".gif"))
            return "image/gif";
        if ( file.toLowerCase().endsWith(".jpg"))
            return "image/jpg";
        if ( file.toLowerCase().endsWith(".class"))
            return "application/x-java-applet";
        if ( file.toLowerCase().endsWith(".zip"))
            return "application/x-zip-compressed";
        if ( file.toLowerCase().endsWith(".wav"))
            return "audio/basic";
        if ( file.toLowerCase().endsWith(".exe"))
            return "application/octet-stream";
        
        return "text/plain; charset=\"us-ascii\""; // default
    }

    // send the attachment if it exists
    private  void sendAttachment( String MimeType) {
    String strip = AttachedFile;
     if ( (AttachedFile.lastIndexOf("\\")) != -1){
        //strip out the path info 
        StringTokenizer tok = new StringTokenizer(strip,"\\");
        while ( tok.countTokens() >1) tok.nextToken();
        strip = tok.nextToken(); // raw file name
     } 
     send(out,"Content-Type:" + MimeType + "; name="+ strip);
     send(out,"Content-Disposition: attachment;filename=\""+strip+"\"");
     send(out,"Content-Transfer-Encoding: base64\n");
     Base64Encode(AttachedFile,out);
     send(out,"\n--StartOfNextPart--"); // end of multipart transmission
    }
    

 
   private void Base64Encode(String filename, BufferedWriter out) {
     // I ripped this off somewhere a while back. Author unknown. Slightly
     // modified from the original
     try {
       File f              = new File(filename);
       FileInputStream fin = new FileInputStream(filename);
       byte bytes[]        = new byte[(int)(f.length())];
       int n               = fin.read(bytes);
       if (n < 1) 
            return;          
       byte buf[] = new byte[4];   
       int n3byt      = n / 3;     
       int nrest      = n % 3;     
       int k          = n3byt * 3; 
       int linelength = 0;         
       int i          = 0;         
       while ( i < k ) {
        buf[0] = (byte)(( bytes[i]   & 0xFC) >> 2); 
        buf[1] = (byte)(((bytes[i]   & 0x03) << 4) | 
                   ((bytes[i+1] & 0xF0) >> 4));
        buf[2] = (byte)(((bytes[i+1] & 0x0F) << 2) | 
                   ((bytes[i+2] & 0xC0) >> 6));
        buf[3] = (byte)(  bytes[i+2] & 0x3F);
        
        out.write(BaseTable[buf[0]]+BaseTable[buf[1]]+
                     BaseTable[buf[2]]+BaseTable[buf[3]]);
        
       if ((linelength += 4) >= 72) {
           out.write( "\r\n");
           linelength = 0;
           }
        i += 3;
        }
       if (nrest==2) {
         buf[0] = (byte)(( bytes[k] & 0xFC)   >> 2);
         buf[1] = (byte)(((bytes[k] & 0x03)   << 4) | 
                    ((bytes[k+1] & 0xF0) >> 4));
         buf[2] = (byte)(( bytes[k+1] & 0x0F) << 2); 
         } 
       else if (nrest==1) {
         buf[0] = (byte)((bytes[k] & 0xFC) >> 2);
         buf[1] = (byte)((bytes[k] & 0x03) << 4);
         }
       if (nrest > 0) {
        if ((linelength += 4) >= 72) out.write("\r\n");
        
       if (nrest==2) {
           out.write(BaseTable[buf[0]]+ BaseTable[buf[1]] +BaseTable[buf[2]]);
           out.write("=");
           //out.write("=");
           }
       else{
           out.write(BaseTable[buf[0]]+ BaseTable[buf[1]]);
           out.write("=");
           }
        }
       out.flush();
       }catch (Exception e) {}
    }

}
