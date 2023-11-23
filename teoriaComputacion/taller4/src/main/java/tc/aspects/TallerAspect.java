package tc.aspects;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;

import tc.aspects.util.Color;

/**
 * Complete este aspecto para que haga lo siguiente:
 * 1 (50%). Intercepte todos los llamados (call) a los getters de clases en el paquete tc.aspects.data 
 *   que hayan sido llamados desde la clase University
 * 		- Imprima por pantalla la firma completa del método interceptado y la línea en el código donde se produjo la intercepción
 * 
 * 2 (50%). Intercepte todas las ejecuciones (execution) a los setters de clases en el paquete tc.aspects.data 
 *   cuya clase esté anotada con @Auditable
 * 		- Imprima por pantalla la firma completa del método interceptado y el valor enviado como parámetro al setter
 * 
 * NOTA: Para hacer pruebas, si es necesario, modifique el resto del código. Explique dichas modificaciones en el video
 */

@Aspect
public class TallerAspect {

    @Before("call(* tc.aspects.data..get*(..)) && within(tc.aspects.data.University)")
    public void interceptGetters(JoinPoint joinPoint) {
		System.out.println(Color.BLUE);
        System.out.println("Interceptando getter: " + joinPoint.getSignature() +
                           " en la línea: " + joinPoint.getSourceLocation().getLine());
        System.out.println(Color.RESET);
    }

    @Before("execution(* tc.aspects.data..set*(..)) && (@target(tc.aspects.annotations.Auditable) || @target(tc.aspects.annotations.Auditable2) || @target(tc.aspects.annotations.Auditable3) || @target(tc.aspects.annotations.Auditable4) || @target(tc.aspects.annotations.Auditable5))")
    public void interceptSetters(JoinPoint joinPoint) {
        Object[] args = joinPoint.getArgs();
        System.out.println(Color.BLUE);
        if (args.length > 0) {
            System.out.println("Interceptando setter: " + joinPoint.getSignature() +
                               " con valor: " + args[0]);
        }
        System.out.println(Color.RESET);
    }
}