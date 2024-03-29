package tc.aspects.data;

import java.util.ArrayList;
import java.util.List;

public class University {
    String tid;
    String name;

    List<Teacher> teachers = new ArrayList<>();
    List<Student> students = new ArrayList<>();

    public String getTid() {
        return tid;
    }

    public String getName() {
        return name;
    }

    public void setTid(String tid) {
        this.tid = tid;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void getTeacherNames() {
        System.out.println("Getting teacher names");
        for (Teacher teacher : teachers) {
            System.out.println(teacher.getName());
        }
    }
    
    public void addTeacher(String id, String name, String lastName, Integer age) {
        System.out.println("Adding teacher " + name );
        Teacher t = new Teacher();
        t.setId(id);
        t.setName(name);
        t.setLastName(lastName);
        t.setAge(age);

        teachers.add(t);
    }

    public void getStudentNames() {
        System.out.println("Getting student names");
        for (Student student : students) {
            System.out.println(student.getName());
        }
    }

    public void addStudent(String id, String name, String lastName, Integer age) {
        System.out.println("Adding student " + name );
        Student s = new Student();
        s.setId(id);
        s.setName(name);
        s.setLastName(lastName);
        s.setAge(age);

        students.add(s);
    }
}
