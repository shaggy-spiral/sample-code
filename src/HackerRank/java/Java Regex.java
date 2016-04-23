/*
Write a class called myRegex which will contain a string pattern. You need to write a regular expression and assign it to the pattern such that it can be used to validate an IP address.
*/
class myRegex {
    String pattern;
    Pattern pat;
    public myRegex() {
        pattern = "^([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])\\.([01]?\\d\\d?|2[0-4]\\d|25[0-5])$";
        pat.compile(pattern);
        
    }

}
